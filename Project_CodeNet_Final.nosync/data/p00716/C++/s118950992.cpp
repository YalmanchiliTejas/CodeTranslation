#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int req1(int st,double b,double c,int y,bool f){
    int rsum=0;
    int u=0;

    for(int i=0;i<y;i++){
        int bb=st*b;
        if(!f){
            rsum+=bb;
            st-=c;
        }else {
            st = st + bb - c;
        }

    }
    if(!f){
        st+=rsum;
    }
    return st;



}


int main() {

    int n;
    cin >> n;
   rep(nn,n){

        if(n==0)break;
        int st,y,x;
        cin>>st>>y>>x;
        vector<int> money(x);
        rep(i,x){
            bool a;
            double b,c;
            cin>>a>>b>>c;
                money[i]=req1(st,b,c,y,a);

        }
        sort(money.rbegin(),money.rend());
        cout<<money[0]<<endl;


    }


    return 0;
}

