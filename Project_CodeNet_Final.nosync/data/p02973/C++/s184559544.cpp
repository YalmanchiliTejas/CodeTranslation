#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
using namespace std;



const long long int mod=1000000007;
const long long int INF=99999999999999999;
long long int mode=0;
string s,t;

long long int n,w,d,a[310000],q,L[120000],R[120000],mp_consumption[100000];
pair<long long int,long long int>ij[300005];

//最長単調増加列,0-indexed,要素数Nと配列a
class LIS{
    public:
    
	long long int LIS_Do(long long int N,long long int a[]){
		long long int LIS_table[250005];
		long long int LIS_start=250000,now=LIS_start,ng=now,ok=now+1,mid;
		for(int i=0;i<=LIS_start;i++){
			LIS_table[i]=INF;
		}
		for(int i=0;i<N;i++){
			ng=now;
			ok=LIS_start+1;
			
			while(ok-ng>1){
				mid=(ng+ok)/2;
				if(LIS_table[mid]>a[i]){
					ng=mid;
				}else{ok=mid;}
			}
			
			LIS_table[ng]=a[i];
			if(ng==now){
				now--;
			}
			
		}
		for(int i=LIS_start;i<=now;i++){
			cout<<LIS_table[i]<<endl;
		}
		return LIS_start-now;
	}
    
};

int main() {
	cout << fixed << setprecision(18);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=10000000000-a[i];
    }
    LIS lis;
    cout<<lis.LIS_Do(n,a);

} 
