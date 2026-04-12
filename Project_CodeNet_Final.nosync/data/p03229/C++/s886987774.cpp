#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    sort(v.begin(), v.end());
    /*小さい奴を真ん中にする場合*/
    deque<ll>que1;
    rep(i, n) que1.push_back(v[i]);
    ll ans1 = 0;
    ll left = que1.front();
    ll right = left;
    que1.pop_front();
    int idx = 0;
    while(!que1.empty()){
        if(que1.size()==1){
            ll a = que1.front();
            ans1 += max(abs(left-a), abs(right-a));
            que1.pop_front();
        }
        else {
            ll a, b;
            if(idx%2){
                a = que1.front();
                que1.pop_front();
                b = que1.front();
                que1.pop_front();
            }
            else{
                a = que1.back();
                que1.pop_back();
                b = que1.back();
                que1.pop_back();
            }
            ll c = abs(a-left)+abs(b-right);
            ll d = abs(a-right)+abs(b-left);
            if(c>d){
                left=a;
                right=b;
                ans1 += c;
            }
            else {
                left=b;
                right=a;
                ans1 += d;
            }
        }
        idx++;
    }
    deque<ll>que2;
    rep(i, n) que2.push_back(v[i]);
    ll ans2 = 0;
    ll left2 = que2.back();
    ll right2 = left2;
    que2.pop_back();
    int idx2 = 0;
    while(!que2.empty()){
        if(que2.size()==1){
            ll a = que2.front();
            ans2 += max(abs(left2-a), abs(right2-a));
            que2.pop_front();
        }
        else {
            ll a, b;
            if(idx2%2==0){
                a = que2.front();
                que2.pop_front();
                b = que2.front();
                que2.pop_front();
            }
            else{
                a = que2.back();
                que2.pop_back();
                b = que2.back();
                que2.pop_back();
            }
            ll c = abs(a-left2)+abs(b-right2);
            ll d = abs(a-right2)+abs(b-left2);
            if(c>d){
                left2=a;
                right2=b;
                ans2 += c;
            }
            else {
                left2=b;
                right2=a;
                ans2 += d;
            }
        }
        idx2++;
    }
    cout<<max(ans1, ans2)<<endl;
    return 0;
}