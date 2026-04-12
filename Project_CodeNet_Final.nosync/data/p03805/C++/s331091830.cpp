#include <iostream>
using namespace std;

int n, m;
int a[28], b[28];

int route(bool alrdy[], int cnt, int now){
    if(cnt == n){
        return 1;
    }
    
    int ans = 0;
    int i;
    for(i = 0; i < m; i++){
        if(a[i] == now && alrdy[b[i]] == false){
            alrdy[b[i]] = true;
            ans += route(alrdy, cnt + 1, b[i]);
            alrdy[b[i]] = false;
        }
        if(b[i] == now && alrdy[a[i]] == false){
            alrdy[a[i]] = true;
            ans += route(alrdy, cnt + 1, a[i]);
            alrdy[a[i]] = false;
        }
    }
    
    return ans;
}

int main(void){
    cin >> n >> m;
    
    int i;
    for(i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }
    
    bool alrdy[9] = {false, true};
    int ans = route(alrdy, 1, 1);
    
    cout << ans << endl;
    
    return 0;
}
