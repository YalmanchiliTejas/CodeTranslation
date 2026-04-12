#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

int main(){
    int n;
    int i,j;
    string s,t;
    cin>>n;
    rep(i,0,n){
        cin>>s;
        sort(s.begin(),s.end());
        if(i==0){
            t=s;
        }
        else{
            if(0!=t.size()){
                j=0;
                while(1){
                    if(s.find(t[j])!=string::npos){
                        s.erase(s.begin()+s.find(t[j]));
                        j++;
                    }
                    else{
                        t.erase(t.begin()+j);
                    }
                    if(j==t.size()){
                        break;
                    }
                }
            }
        }
    }
    cout<<t<<endl;
}
