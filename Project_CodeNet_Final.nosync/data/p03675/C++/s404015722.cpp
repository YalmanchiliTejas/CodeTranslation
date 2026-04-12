#include <bits/stdc++.h>
#define INF 1e+9
#define debug(x) cerr << #x << ": " << x << "\n";
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[200010];

int main(void){
    int N; cin >> N;
    deque<int> que;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(i%2 == 0) que.push_back(a);
        else que.push_front(a);
    }

    if(N%2 == 1) reverse(begin(que), end(que));

    cout << que.front();
    que.pop_front();
    while(not que.empty()){
        cout << ' ' << que.front();
        que.pop_front();
    }
    cout << endl;

    return 0;
}