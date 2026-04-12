#include <bits/stdc++.h>
using namespace std;
int countMAX(int x, int k){
    if (k == 0) return 1;
    if (k == 1) return x * 9;
    if (k == 2) return x*(x-1)/2 * 81;
    if (k == 3) return (x*(x-1)*(x-2))/6 * 729;
}
string n;
int nD;
int p;
int dp(int curID, int left, int ok){
    if (curID == nD+1) return (left==0);
    if (left < 0) return 0;
    if (ok){
        return countMAX(nD-curID+1,left);
    }
    int X = n[curID-1]-'0';
    int ans = 0;
    for (int j = 0; j < X; j++){
        ans += dp(curID+1,left-(j!=0),true);
    }
    ans += dp(curID+1,left-(X!=0),false);
    //printf("%d %d %d %d %d\n",curID,left,ok,X,ans);
    return ans;
}
int main(){
    cin >> n >> p;
    nD = n.size();
    printf("%d",dp(1,p,0));

}
