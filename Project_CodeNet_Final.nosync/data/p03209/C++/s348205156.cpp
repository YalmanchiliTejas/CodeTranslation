#include <iostream>
#include <cmath>
using namespace std;

long long bp(long long i, int j){
    if(i){
       if(i+1>=pow(2, j+1))
       {
           if(i+3==pow(2, j+2)) return pow(2, j+1)-1;
           else return pow(2, j)+bp(i-pow(2, j+1)+1, j-1);
       }
       else return bp(i-1, j-1);
    }
    else return 0;
}

int main() {
	int N;
	long long X;
    cin >> N >> X;
    cout << bp(X, N) << endl;
    return 0;
	return 0;
}
