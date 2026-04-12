#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
//#define int long long  
int main(){
    int N;
    int a[214514];
    int now=0;
    cin >> N;
    REP(i,N){cin >> a[i];}
    if(N%2==0){
        REP(i,N/2){
            cout << a[N-2*i-1];
            if(now!=N-1)cout << " ";
            now++;
        }
        REP(i,N/2){
            cout << a[2*i];
            if(now!=N-1)cout << " ";
            now++;
        }
    }else{
        REP(i,N/2){
            cout << a[N-2*i-1];
            if(now!=N-1)cout << " ";
            now++;
        }
        cout << a[0] << " ";
        REP(i,N/2){
            cout << a[2*i+1];
            if(now!=N-1)cout << " ";
            now++;
        }
    }
    cout << endl;

return 0;
}