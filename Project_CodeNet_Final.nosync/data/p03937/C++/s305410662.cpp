#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
    int h, w;
    cin >> h >> w;
    int sharp = 0;
    for(int i = 0; i < h*w; i++){
        char t;
        cin >> t;
        if(t=='#'){sharp++;}
    }
    if(sharp == h+w-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
