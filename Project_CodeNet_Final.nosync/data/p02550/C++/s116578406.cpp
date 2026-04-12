#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    long long int ii,n,m,x;
    long long int ans[100000]={0};
    long long int ansz;
    bool flag = true;
    unordered_set<long long int > s;
    cin >> n >> x >> m;
    ans[1]= x;
    for(long long int i = 2; i <=n; i++){
        x = ((x%m)*(x%m)%m);
        if(s.find(x)!=s.end()){
            for(int j =1;j < i ;j++){
                if(ans[j]-ans[j-1] == x){
                    ii = j;
                    break;
                }
            }
            ansz = ans[(n-ii)%(i-ii)+ii]+  (ans[i-1]- ans[ii-1]) * ((n-ii)/(i-ii)); //ここあとでかく
            //cout << ans[(n-ii)%(i-ii)+ii] << " " << (ans[i-1]- ans[ii-1]) << " "  << (n-ii)/(i-ii) << endl;
            flag = false;
            break;
        }else{
            ans[i]= x + ans[i-1];
            s.insert(x);
        }
    }
    if(flag){
        cout << ans[n] << endl;
    }else{
        cout << ansz << endl;
    }
}