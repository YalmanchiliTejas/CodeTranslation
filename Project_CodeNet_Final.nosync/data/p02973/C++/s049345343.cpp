#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
#define P pair<int,int>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a;
    rep(i,n){
        int num; cin >> num;
            if(a.empty()){
                a.push_back(num);
                continue;
            }
            if(num<=a[a.size()-1]){
                a.push_back(num);
                continue;
            }
            int l=0; int r=a.size()-1;
            while(r!=l){
                int next=(r+l)/2;
                if(a[next]<num) r=next;
                else l=next+1;
            }
            a[r]=num;
    }

    cout << a.size() << endl;
return 0;
}
