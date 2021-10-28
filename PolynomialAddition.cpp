#include <iostream>
#include <vector>
#include <string>

int COMPARE(int exponenta, int exponentb);

using namespace std;

typedef struct{
        int coef;
        int expon;
}polynomial;

int avail=0;

int main() {
	
	polynomial add_polynomial;
	vector<polynomial> pvec;

        int starta=0, finisha=0, startb=0, finishb=0;
        int length_a=0, length_b=0;
        int i=0;
        int coefficient=0;

        cin >> length_a;
        finisha = length_a-1;
        startb = length_a;
        for(i=starta; i<=finisha; i++){
                cin >> add_polynomial.coef >> add_polynomial.expon;
                pvec.push_back(add_polynomial);
        }

        cin >> length_b;
        finishb = startb + length_b - 1;
        for(i=startb; i<=finishb; i++){
                cin >> add_polynomial.coef >> add_polynomial.expon;
                pvec.push_back(add_polynomial);
        }

	avail = length_a + length_b;
        while (starta <= finisha && startb <= finishb) {
                switch (COMPARE (pvec[starta].expon,pvec[startb].expon)) {
                        case -1: /* a expon < b expon */
                                add_polynomial.coef = pvec[startb].coef;
				add_polynomial.expon = pvec[startb].expon;
                                pvec.push_back(add_polynomial);
				startb++;
                                avail++;
                                break;
                        case 0: /* equal exponents */
                                coefficient = pvec[starta].coef + pvec[startb].coef;

				add_polynomial.coef = coefficient;
                                add_polynomial.expon = pvec[startb].expon;
                                pvec.push_back(add_polynomial);

                                avail++;
				starta++;
                                startb++;
                                break;
                        case 1: /* a expon > b expon */
                                add_polynomial.coef = pvec[starta].coef;
                                add_polynomial.expon = pvec[starta].expon;
                                pvec.push_back(add_polynomial);

                                avail++;
                                starta++;
                                break;
                }
        }
        /* add in remaining terms of A(x) */
        for(; starta <= finisha; starta++){
               add_polynomial.coef = pvec[starta].coef;
               add_polynomial.expon = pvec[starta].expon;
               pvec.push_back(add_polynomial);

               avail++;
	}
        /* add in remaining terms of B(x) */
        for( ; startb <= finishb; startb++){
               add_polynomial.coef = pvec[startb].coef;
               add_polynomial.expon = pvec[startb].expon;
               pvec.push_back(add_polynomial);
	
                avail++;

	}

        for(i=finishb+1; i<avail; i++){
        	if(pvec[i].coef != 0){
        		cout << pvec[i].coef << " " << pvec[i].expon << " " ;
		}
        }
        
    return 0;
}

int COMPARE(int exponenta, int exponentb){
        if(exponenta > exponentb){
                return 1;
        }
        else if(exponenta == exponentb){
                return 0;
        }
        else{
                return -1;
        }

}
