#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
 
 	int n;
 	char s[100005];
 	bool A[100005];
 	cin >> n >> s;
 	s[n]=s[0];
 	s[n+1]=s[1];
 
 	rep(i, 4){
 		A[0]=i&1;
 		A[1]=(i>>1)&1;
 		for(int i=2;i<n+2;i++){

 			// sheep and x || wolf and o
			if(A[i-1]^(s[i-1]=='o'))
				A[i]=A[i-2]^1;
			else 
				A[i]=A[i-2];
		}
 		if(A[n]==A[0] && A[n+1]==A[1]){
 			rep(i,n){
 				if(A[i])
 					cout << 'S';
 				else
 					cout << "W";
 			}
 			return 0;
 		}
 	}
 
 	cout << -1 << endl;
    
    return 0;
}
