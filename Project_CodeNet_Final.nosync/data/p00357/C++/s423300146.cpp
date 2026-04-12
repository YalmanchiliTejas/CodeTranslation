#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> dist(N);
    for(int i=0;i<N;i++) cin >> dist[i];
    bool ok = true;

    int MAX = 0;
    for(int i=0;i<=min(N-1,MAX);i++) MAX = max(MAX, i+dist[i]/10);
    if(MAX < N-1) ok = false;

    MAX = 0;
    reverse(dist.begin(), dist.end());
    for(int i=0;i<=min(N-1,MAX);i++) MAX = max(MAX, i+dist[i]/10);
    if(MAX < N-1) ok = false;

    if(ok) cout << "yes" << endl;
    else cout << "no" << endl;
}
