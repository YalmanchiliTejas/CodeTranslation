#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
#define ll long long
#define ull unsigned ll
using namespace std;
#define MAXN 60

ll data[MAXN];
int n;

ll maxnum , maxpos;
void getmax(){
	maxnum = -1;
	for( int i = 1 ; i <= n ; i++ )
		if( data[i] > maxnum ){
			maxnum = data[i];
			maxpos = i;
		}
}

int main(){
	//freopen("E.txt","r",stdin);
	
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%lld",&data[i]);
	
	ll ans = 0;
	getmax();
	while( maxnum >= n ){
		ll huan = (maxnum-(n-1)) % n;
		ll dec = (maxnum-(n-1)) / n;
		//cout << "[] " << huan << " " << dec << endl;
		if( huan ){
			dec++;
		}
		ans += dec;
		for( int i = 1 ; i <= n ; i++ ){
			if( i == maxpos )
				data[i] -= dec*n;
			else
				data[i] += dec;
		}
		//for( int i = 1 ; i <= n ; i++ )
		//	cout << data[i] << " ";
		//cout << endl;
		//for( ll i = 1 ; i <= 100000000;i++);
		getmax();
	}
	printf("%lld\n",ans);
	return 0;
};