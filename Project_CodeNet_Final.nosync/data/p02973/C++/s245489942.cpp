#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int
const int MAX = 510000;


using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> S;
    int a[n];
    rep(i, n){
        cin >> a[i];
    }
    //int ans = 1;
    reverse(a, a + n);
    //S.insert(a[0]);
    rep(i, n){
        auto ii = S.upper_bound(a[i]);
        if(ii == S.end()) S.insert(a[i]);
        else{
            S.erase(ii);
            S.insert(a[i]);
        }
    }
    cout << S.size() << endl;


    /*
    priority_queue<P, vector<P>, greater<P>> G;
    G.push(a[n - 1]);
    for(int i = n - 2; i >= 0; i --){
        priority_queue<P, vector<P>, greater<P>> G_1;
        bool update = false;
        while(!G.empty()){
            P c = G.top();
            G.pop();
            if(c.first > a[i].first){
                P jj; jj.first = a[i].first;
                jj.second = c.second;
                G.push(jj);
                while(!G_1.empty()){
                    P gg = G_1.top();
                    G.push(gg);
                    G_1.pop();
                }
                update = true;
                break;
            }else{G_1.push(c);
            }
        }
        if(!update){
            G.push(a[i]);
            while(!G_1.empty()){
                P gg = G_1.top();
                G.push(gg);
                G_1.pop();
            }break;
        }

    }
    cout << G.size() << endl;
    //cout << G.top().first << endl;*/
}