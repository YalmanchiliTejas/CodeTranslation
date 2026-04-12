#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const int INF = 1e9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
//    freopen("out.txt", "w", stdout);

    ll N;
    int X, M; cin >> N >> X >> M;
    bool visited[M];
    fill(visited, visited+M, false);

    ll a = X;
    for(int i = 0; i <= M; i++){
        if(visited[a]) break;
        visited[a] = true;
        a = (a*a)%M;
    }

    int start = 0;
    vll sstart; vll scycle;
    sstart.push_back(0);
    scycle.push_back(0);
    ll A = a;
    a = X;

    while(a != A){
        start++;
        sstart.push_back(sstart[sstart.size()-1]+a);
        a = (a*a)%M;
    }

    int cycle = 1;
    scycle.push_back(a);
    a = (a*a)%M;

    while(a != A){
        cycle++;
        scycle.push_back(scycle[scycle.size()-1]+a);
        a = (a*a)%M;
    }

    
    if(N <= start)
        cout << sstart[N];
    else
        cout << sstart[start] + (N-start)/cycle*scycle[cycle]+scycle[((N-start)%cycle)];
    return 0;

}
