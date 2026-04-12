#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int>P;
int main(){

    int N;
    cin>>N;
    vector<P>V(N), IDX(N);
    vector<P>W(N);
    vector<P>H(N);
    for(int i=0;i<N;i++){
        cin>>V[i].first>>V[i].second;
        W[i].first = V[i].first;
        W[i].second = i;
        H[i].first = V[i].second;
        H[i].second = i;
    }
    sort(W.begin(), W.end());
    sort(H.begin(), H.end());
    for(int i=0;i<N;i++){
        IDX[W[i].second].first = i;
        IDX[H[i].second].second = i;
    }
    priority_queue<P, vector<P>, greater<P> >Q;
    vector<int>flg(N, 0);
    ll ans = 0;
    Q.push(P(0, 0));
    while(!Q.empty()){
        P p = Q.top();
        Q.pop();
        if(flg[p.second])continue;
        ans+=p.first;
        flg[p.second]=1;
        int widx = IDX[p.second].first;
        int hidx = IDX[p.second].second;
        if(0<widx){
            if(flg[W[widx-1].second]==0){
                Q.push(P(W[widx].first - W[widx-1].first, W[widx-1].second));
            }
        }
        if(widx+1<N){
            if(flg[W[widx+1].second]==0){
                Q.push(P(W[widx+1].first - W[widx].first, W[widx+1].second));
            }
        }
        if(0<hidx){
            if(flg[H[hidx-1].second]==0){
                Q.push(P(H[hidx].first - H[hidx-1].first, H[hidx-1].second));
            }
        }
        if(hidx+1<N){
            if(flg[H[hidx+1].second]==0){
                Q.push(P(H[hidx+1].first - H[hidx].first, H[hidx+1].second ));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}