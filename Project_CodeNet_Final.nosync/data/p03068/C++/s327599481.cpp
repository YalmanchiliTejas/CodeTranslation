#include<stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main( void )
{
    int K, N;
	cin >> N;
    string S;
	cin >> S;

	cin >> K;

    int l = S.size();
    for(int i=0;i<l;i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }

    cout << S << "\n";
	return 0;
}