#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int ans=1,max=h[0];
    
    for(int i=1;i<n;i++){
        if(h[i]>=max){
            ans++;
            max=h[i];
        }
    }

    cout << ans << endl;
}