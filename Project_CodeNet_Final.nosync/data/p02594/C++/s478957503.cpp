
    #include <bits/stdc++.h> 
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


using namespace std;
#define M 1000000001
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repb(i,a,b) for(int i=a;i>=b;--i)
#define repv(arr)  for(auto it=arr[i].begin();it!=arr[i].end();++it)  
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define vc vector<char>
#define sz(a) (int)a.size()
#define ssortA(arr)   stable_sort(arr.begin(),arr.end())
#define ssortB(arr)   stable_sort(arr.begin(),arr.end(),greater<int>());
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define search(arr,c)  binary_search(arr.begin(),arr.end(),c)
#define pb   push_back
#define ll long long
#define mp make_pair
#define endl "\n" 
#define LCM(a,b) boost::math::lcm(a,b)
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define check(ds,x) (int)(ds.find(x)!=ds.end()?1:0)
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n>=30)cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }
    }