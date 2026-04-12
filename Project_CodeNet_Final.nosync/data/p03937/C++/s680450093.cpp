#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long;
#define MM = 1000000000;
#define mod = MM + 7;
#define INF (ll)1e18
#define pi acos(-1.0)
#define MAX 100005
#define NIL -1
int main(){
    int h, w; cin >> h >> w;
    char a;
    int sum = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a;
            if(a == '#') sum++;
        }
    }
    if(sum == h+w-1) cout << "Possible";
    else cout << "Impossible";
    cout << endl;
}