#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>
#include<map>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++) 
#define lint long long
#define all(x) (x).begin(), (x).end()

int main(){
    long n, x; cin>>n>>x;
    long sta, end, ans;
    sta = 1; end = pow(2, n+2)-3; ans = 0;
    long l = n-1;


    while(sta <= end && l >= -1){
        long mid = (sta+end)/2;
        if (x < mid){
            sta++;
            end = mid-1;
        }else if (x == mid){
            ans +=  pow(2, l+1);
            break;
        }
        else{
            ans += pow(2, l+1);
            sta = mid+1;
            end--;
        }
        l--;
    }
    cout << ans << endl;
}