#include<cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int N;
    long long x;
    vector<pair<long long, int>> X;
    vector<pair<int, long long>> ans;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        X.push_back(make_pair(x, i));
    }

    sort(X.begin(), X.end());

    for(int i=0; i<N; i++){
        int n = X[i].second;
        if(i <= N/2 - 1) ans.push_back(make_pair(n, X[N/2].first));
        else ans.push_back(make_pair(n, X[N/2 - 1].first));
    }

    sort(ans.begin(), ans.end());

    for(int i=0; i<N; i++){
        cout << ans[i].second << endl;
    }
}
