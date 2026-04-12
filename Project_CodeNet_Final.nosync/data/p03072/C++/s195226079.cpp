#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,cnt;cin >> a;
    vector<int> n(a+1);
    for(int i=0;i<a;i++){
        cin >> n[i];
    }

    cnt = 1;
    b = n[0];

    for(int j=1;j<a;j++){
        if(n[j]>=b){
            cnt++;
            b = n[j];
        }else{
            continue;
        }
    }

    cout << cnt << endl;
}