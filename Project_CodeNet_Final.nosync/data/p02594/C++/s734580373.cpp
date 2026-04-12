#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define loop(i ,a,b) for(int i = a;i<b;i++)
#define rloop(i,a,b) for(int i = a ; i>b;i--)
#define loopll(i,a,b) for( long long int i = a; i<b;i++)
#define rloopll(i,a,b) for(long long int i = a; i>b;i--)
#define eb emplace_back
#define pii pair<int ,int>
#define pll pair<ll ,ll>
#define mk make_pair
#define intmin INT_MIN
#define intmax INT_MAX
#define cout(x) cout<<x<<" ";
using namespace std;
void vec(vector<int> & v){

    for(int i = 0;i<v.size() ; i++){
        cout<<v[i]<< " ";
    }
    cout<<endl;
}
void vec_ll(vector<long long int> & v){

    for(int i = 0;i<v.size() ; i++){
        cout<<v[i]<< " ";
    }
    cout<<endl;
}
int parsestring(string temp){
    int num= 0;
    int digs = temp.size() - 1;
    for(int i = 0 ;i<=digs;i++){
        num += pow(10 , digs -i)*(temp[i] - '0');
    }
    return num;
}
int main(){
    int x;
    cin>>x;
    if(x  >=30){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
}
