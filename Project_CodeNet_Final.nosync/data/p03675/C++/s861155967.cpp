#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}
int A[200005]; 
int B[200005] ;
int mark[200005] ;
int main(int argc,char* argv[]) { 
    io() ;
    int n ;
    cin >> n ;
    for(int i = 1; i <= n; i++){
        cin >> A[i] ;
    }
    for(int i = n ; i >= 1 ; i -= 2){
        mark[i] = 1 ;
        cout << A[i] << " " ;
    }
    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            cout << A[i] << " " ;
        }
    }
    return 0 ; 
}