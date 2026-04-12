#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int nmax = 200100;
int N;
int a[nmax];
int b[nmax];

void read(){
    cin >> N;
    for(int i=0;i < N; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
}

void solve(){
    sort(a, a  + N);
    int l = (N + 1) / 2 - 1;
    for(int i = 0 ; i < N; ++i)
    {
        if(b[i] <= a[l]) 
            cout << a[l+1] << endl;
        else
            cout << a[l] << endl;
    }
}

int main(){
    read();
    solve();
}