#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


int N;
int X[200010];
pii XX[200010];
int ans[200010];

int main(){
    

    cin >> N;
    for(int i = 0; i < N; i++) cin >> X[i], XX[i] = pii(X[i], i);
    sort(XX, XX + N);
    for(int i = 0; i < N; i++){
        if(i < N / 2){
            ans[XX[i].second] = XX[N/2].first;
        }
        else if(i >= N / 2){
            ans[XX[i].second] = XX[N/2-1].first;
        }        
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

}
