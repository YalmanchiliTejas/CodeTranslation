#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;
const int MAX=1001;
int a[MAX];
int b[MAX];
int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

      string s;
      cin>>s;
      int a=0,b=0;
      for(int i=0; i<3; i++){
        if(s[i]=='A'){
            a++;
        }
        else{
          b++;
        }
      }
      if((b==2 && a==1) || (b==1 && a==2)){
       cout<<"Yes"<<endl;
      }
      else {
        cout<<"No"<<endl;;
      }

}

