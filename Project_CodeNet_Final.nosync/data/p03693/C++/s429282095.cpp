#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

#define mp make_pair
#define pb push_back
#define mp make_pair

bool graph[1000][1000];

vector<int>g[100100];

int main(){
    ll r,g,b;
    cin >> r>> g>>b;
    ll mx;
    mx= r*100+g*10+b;
    if(mx%4==0){
        cout<<"YES";
    }
    else cout<<"NO";

    return 0;

}
