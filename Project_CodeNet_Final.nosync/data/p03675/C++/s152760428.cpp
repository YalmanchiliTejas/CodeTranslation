#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#endif 

using namespace std;

int main(void){
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    REP(i,n)
        cin >> a[i];
    
    if( n == 1 ){
        cout << a[0] << endl;
        return 0;
    }
    

    for(int i = n-1; i >= 0 ; i-=2 ){
            cout << a[i] << " ";
        }
        
    for(int i = n%2 ; i < n-2 ; i+=2 ){
        cout << a[i] << " ";
    }
    cout << a[n-2] << endl;
    /*
    if( n % 2 == 0 ){
        for(int i = n-1; i >= 0 ; i-=2 ){
            cout << a[i] << " ";
        }
        
        for(int i = 0 ; i < N-2 ; i+=2 ){
            cout << a[i] << " ";
        }
        cout << a[N-2] << endl;
        
    }else{
        for(int i = n-1; i >= 0 ; i-=2 ){
            cout << a[i] << " ";
        }
        
        for(int i = 1 ; i < N-2 ; i+=2 ){
            cout << a[i] << " ";
        }
        cout << a[N-2] << endl;
    }
    */
    
    
    return 0;
}
