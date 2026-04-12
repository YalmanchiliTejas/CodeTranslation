#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, q; cin>>n>>q;
    int head=1;

    for(int i=0; i<q; i++){
        int x, y; cin>>x>>y;
        if(x == 0){
            if(y + head <= n + 1){
                cout << head + y - 1 << endl;
            }
            else{
                cout << y + head - (n + 1) << endl;
            }
        }
        else{
            if(y + head <= n){
                head=head+y;
            }
            else{
                head=head+y-n;
            }
        }
        //cout << "head" << head << endl;
    }
}
