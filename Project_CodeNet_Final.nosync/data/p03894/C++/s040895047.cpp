#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int num[100000] = {0};
    num[1] = 1;
    int pos = 0;
    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a == pos){
            pos = b;
        }else if(b == pos){
            pos = a;
        }
        swap(num[a], num[b]);
        for(int p : {pos-1, pos+1}) if(0 <= p && p < N) num[p]++;
    }
    int ans = 0;
    for(int i=0; i<N; i++) if(pos == i || num[i] > 0) ans++;
    cout << ans << endl;
    return 0;
}
