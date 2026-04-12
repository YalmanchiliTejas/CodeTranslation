#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    vector<ll>b(n);
    SORT(a);
    if(n%2){
        int left = 0;
        int right = n-1;
        FOR(i,1,n-1){
            if(i%2==0){
                b[i] = a[left];
                left++;
            }else{
                b[i] = a[right];
                right--;
            }
        }
        b[0] = a[left];
        b[n-1] = a[right];

        ll answer = 0;
        REP(i,n-1){
            answer+=llabs(b[i]-b[i+1]);
        }

        left = 0;
        right = n-1;

        FOR(i,1,n-1){
            if(i%2){
                b[i] = a[left];
                left++;
            }else{
                b[i] = a[right];
                right--;
            }
        }
        b[0] = a[left];
        b[n-1] = a[right];

        ll answer2 = 0;
        REP(i,n-1){
            answer2+=llabs(b[i]-b[i+1]);
        }
        cout << max(answer,answer2) << endl;
    }else{
        int left = 0;
        int right = n-1;
        FOR(i,1,n-1){
            if(i%2==0){
                b[i] = a[left];
                left++;
            }else{
                b[i] = a[right];
                right--;
            }
        }
        b[0] = a[left];
        b[n-1] = a[right];

        ll answer = 0;
        REP(i,n-1){
            answer+=llabs(b[i]-b[i+1]);
        }
        cout << answer << endl;
    }
    
    return 0;
}