//include,namespace
 #include<bits/stdc++.h>
 #include<iostream> 
 #include <queue>
 #include <vector>
 #include <string>
 using namespace std;
//REPmacro
 #define all(x) (x).begin(),(x).end()             //ソート
 #define FOR(i,x,n)for(int i=(x);i<(n);i++)
 #define FOR_R(i,x,n) for(int i=(n-1);i>=(x);i--)
 #define REP(i, n) FOR(i, 0, n)
 #define REP_R(i, n) FOR_R(i, 0, n)
//long long(define)
 using ll = long long;
 typedef long long ll;
 typedef long long int64;
 typedef long long lint;
 typedef long long lli;
/////////
int main(){

    string A;
	cin >> A;
    bool is = true;
    FOR(i,1,A.size())if(A[i]!=A[i-1]){is = false;}
    if(is == false){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

	//cout <<  << endl;
	return 0; 
}