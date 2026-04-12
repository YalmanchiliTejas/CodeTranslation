#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<assert.h>
#include<stdlib.h>
#include<stack>
using namespace std;
/*********************Contest Template***********************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<int,int> Cord;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);
struct S{
    int a,b; S(){}S(int _a,int _b){
        a=_a;
        b=_b;
    }
    const bool operator<(const S &o) const{
        return a<o.a;
    }
};
priority_queue<int,vector<int>,greater<int>> mpq;
#define SPACE 0
#define NL 1
inline void showAll(vector<int> &v,int NL_or_space){ 
    //0 is space, 1 is NL
    for(int &here:v){
        printf("%d",here);
        printf("%c",(NL_or_space)?'\n':' ');
    }
}
/*********************Contest Template***********************/
const int SIZE= 21;

int arr[SIZE];

int main(){
	int n;	scanf("%d",&n);

	for(int i=1 ; i<=n ; i++)
		scanf("%d",&arr[i]);

	int ans=1;
	for(int i=2 ; i<=n ; i++){
		for(int j=1 ; j<i ; j++){
			if(arr[j]>arr[i]){
				break;
			}
			if(j==i-1) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

