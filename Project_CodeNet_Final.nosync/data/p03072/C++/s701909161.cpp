#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(void){
    int N=0;
    int ans=1;
    int top=0;
    cin >> N;
    vector<int> l(N);
    for(int  i=1; i <= N ; i++){
        cin >> l[i];
    }
    top=l[1];
    for(int i=2; i <= N ; i++){
            if(top<=l[i]){
                top=l[i];
                ans++;
            }
    } 
    cout << ans << endl;
}