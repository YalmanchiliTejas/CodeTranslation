#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main( void )
{
    int N;
	cin >> N;

    int tmpH;
    cin >> tmpH;
    int result = 1;
    for(int i=1;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp >= tmpH){
            tmpH = tmp;
            result++;
        }
    }

    cout << result << "\n";
	return 0;
}