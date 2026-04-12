#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef pair<int,int> P;
typedef long long ll;



int main(void){
    int n;
    string t;
    cin>>n;
    map<char,int>f,x;
    for(int i=0;i<n;i++){
        cin>>t;
        if(i==0){
            for(int j=0;j<t.length();j++){
                f[t[j]]++;
            }
        }
        else{
            for(char m='a';m<='z';m++)x[m]=0;
            for(int j=0;j<t.length();j++){
                x[t[j]]++;
            }
            for(char m='a';m<='z';m++){
                f[m]=min(f[m],x[m]);
            }
        }
    }
    string u="";
    for(char m='a';m<='z';m++){
        if(f[m]!=0){
            for(int j=0;j<f[m];j++){
                u+=m;
            }
        }
    }
    cout<<u<<endl;
    return 0;
}