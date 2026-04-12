#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


vector<P> between;
vector<int> ans;

int get_dist(int a, int b){
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void answer(){
    cout << "!";
    for(auto n:ans)cout << " " << n;
    cout << endl;
    cout.flush();
}

int dist[210800];

int main(){
    int n, s, t;
    cin >> n >> s >> t;
    Int shortest = get_dist(s, t);
    dist[s] = 0;
    dist[t] = shortest;
    for(int i = 1;i <= n;i++){
        if(i == s || i == t)continue;
        dist[i] = get_dist(s, i);
        int r = get_dist(i, t);
        if(dist[i] + r != shortest)continue;
        between.push_back(P(dist[i], i));
        
    }
    sort(between.begin(), between.end());
    between.push_back(P(shortest, t));

    ans.push_back(s);
    int now = 0;
    while(ans.back() != t){
        int nxt = between[now].second;
        if(get_dist(ans.back(), nxt) == dist[nxt] - dist[ans.back()]){
            ans.push_back(nxt);
        }
        now++;
    }
    answer();
    return 0;
}
