#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int maxh=0;
    int inp;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> inp;
        if(inp>=maxh){
            ans++;
            maxh=inp;
        }
    }
    cout << ans << endl;

    return 0;
}