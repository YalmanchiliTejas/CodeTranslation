#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)cin >> s.at(i);
    map<char ,int > alph;
    for(int i='a';i<='z';i++){
        char x=char(i);
        alph[x]=100;
    }
    rep(i,n){
        int m=s.at(i).size();
        map<char ,int > alp;
        for(int i='a';i<='z';i++){
        char x=char(i);
        alp[x]=0;
        }
        rep(j,m){
            alp[s.at(i).at(j)]++;
        }
        for(int i='a';i<='z';i++){
        char x=char(i);
        alph[x]=min(alph[x],alp[x]);
        }
        
    }
    for(int i='a';i<='z';i++){
        char x=char(i);
        rep(j,alph[x]){
            cout << x ;
        }
    }
    cout << endl;

}

