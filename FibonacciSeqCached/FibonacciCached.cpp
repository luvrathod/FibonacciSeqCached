#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;


int FibonacciRecursiveFunc(int nthPos) {
	unsigned long long firstNum = 0; unsigned long long secondNum = 1;
	unsigned long long PastFibonacciCache[300] = { firstNum,secondNum };

	if (find(PastFibonacciCache, end(PastFibonacciCache), nthPos-1) != end(PastFibonacciCache)) {
		return nthPos - 1;
	}
	else {
		for (int i = 2; i < nthPos; i++) {
			PastFibonacciCache[i] = PastFibonacciCache[i - 1] + PastFibonacciCache[i - 2];
			if (i > 300) {
				unsigned long long SecondLastTerm = PastFibonacciCache[299];
				unsigned long long lastTerm = PastFibonacciCache[300];
				PastFibonacciCache[300] = {}; PastFibonacciCache[0] = SecondLastTerm; PastFibonacciCache[1] = lastTerm;
				i - 300;  nthPos - 300;
			}
		}
		return PastFibonacciCache[nthPos%300-1];
	}
}

int main() {
	string inputVAL; int nthPos;
	cout << "Greetings, enter a valid n value | n >= 1\n" << "type exit, quit or break to quit program \n\n" << endl << " ->";
	getline(cin, inputVAL);
	string exit_Methods[3] = { "exit", "quit", "break" };
	while (find(exit_Methods, end(exit_Methods), inputVAL) == end(exit_Methods)) {
		bool exception_caught = true;

		try {
			nthPos = stoi(inputVAL);

			exception_caught = false;
		}
		catch (invalid_argument) {
			cerr << "invalid argument" << endl;
		}
		catch (out_of_range) {
			cerr << "number is too big" << endl;
		}
		catch (exception) {
			cerr << "something went horribly wrong :v" << endl;
		}
		if (!exception_caught) {

			//begintimer for calculation speed
			time_t begin, end;
			time(&begin);
			if (nthPos >= 1) {
				cout << FibonacciRecursiveFunc(nthPos) << endl;
			}
			else {
				cout << "ERR" << endl;
			}


			// measure elapsed time
			time(&end);
			time_t elapsed = end - begin;

			printf("Time measured: %ld seconds.\n\n", elapsed);
		}
		cout << "enter a valid n value | n >= 0 ->";
		getline(cin, inputVAL);
	}
}