#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(),a.end());

    ll ans1 = 0,ans2 = 0;

    int right = a.size() - 1;
    int left = 0;
    int i = 0;
    while(right >= left){
        if(i % 2 == 0){
            ans1 -= 2 * a[left];
            left++;
        }
        else{
            ans1 += 2 * a[right];
            right--;
        }
        i++;
    }
    if(n % 2 == 0){
        ans1 -= a[a.size()/2];
        ans1 += a[a.size()/2 - 1];
    }
    else{
        ans1 += (a[a.size()/2] + a[a.size()/2 - 1]);
    }
    right = a.size() - 1;
    left = 0;
    i = 0;
    while(right >= left){
        if(i % 2 == 0){
            ans2 += 2 * a[right];
            right--;
        }
        else{
            ans2 -= 2 * a[left];
            left++;
        }
        i++;
    }
    right++;
    left--;
    if(n % 2 == 0){
        ans2 -= a[a.size()/2];
        ans2 += a[a.size()/2 - 1];
    }
    else{
        ans2 -= a[a.size()/2];
        ans2 -= a[a.size()/2 + 1];
    }

    cout << max(ans1,ans2) << endl;
    return 0;
}