#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

long h[30];
int main(){
    long n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    long max=h[0];
    long count=1;

    for(int i=1; i<n; i++){
        if( h[i] >= max){
            count++;
            max = h[i];
        }
    }

    cout << count << endl;
    return 0;
}

