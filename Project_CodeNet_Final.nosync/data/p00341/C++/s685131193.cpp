#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REAP(i,a,n) for(int i=(a);i<(n);i++)
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define fr first
#define sc second
#define pb push_back
#define All(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    vector<int> e(12);
    REP(i,12){
        cin >> e[i];
    }
    sort(All(e));
    if(e[0]==e[3]&&e[4]==e[7]&&e[8]==e[11])cout << "yes\n";
    else cout << "no\n";
}

