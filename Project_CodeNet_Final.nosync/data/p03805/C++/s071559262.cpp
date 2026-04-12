#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> connect(n,vector<int>(n));
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        connect[a][b] = 1;
        connect[b][a] = 1;
    }

    int array[n];
    rep(i,0,n){
        array[i]=i;
    }
    int cnt=0;

    do {
        if(array[0]!=0){
            break;
        }
        int check=0;
        rep(i,0,n-1){
            int a = array[i];
            int b = array[i+1];
            if(connect[a][b]!=1){
                check=1;
            }
        }
        if(check==0){
            cnt++;
        }
    }while (next_permutation(array, array+n));

    cout<<cnt<<endl;

    return 0;
}