#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
 
const ll MOD=1e9+7;
const ll INF=1e18;
 
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};


int main(){
    int d[20];
    for(int i = 0;i < 12;i++){
        cin >> d[i];
    }
    sort(d,d+12);
    for(int i = 0;i < 3;i++){
        int c = d[i*4];
        for(int j = 0;j < 4;j++){
            if(d[i*4+j] != c){
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
}
