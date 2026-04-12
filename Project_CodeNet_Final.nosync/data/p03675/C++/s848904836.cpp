 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
LL a[200001];
vector<LL>v;
vector<LL>v2;
int main(){
    cin>>N;
    REP(i,N){
        cin>>a[i];
        if(i%2==0){
           v.push_back(a[i]);
        }else{
           v2.push_back(a[i]);
        }
    }
    reverse(v2.begin(),v2.end());
    v.insert(v.begin(),v2.begin(),v2.end());
    if(N%2==0){
    }else{
       reverse(v.begin(),v.end());
    }
    REP(i,v.size()){
        cout<<v[i];
        if(i!=v.size()-1){
           cout<<" ";
        }else{
           cout<<endl;
        }
    }
    return 0;
}