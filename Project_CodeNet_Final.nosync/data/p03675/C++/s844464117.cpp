#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int n;
int a[200010];
deque<int> b;

int main(){
	scanf("%d" , &n);
	repp(i,0,n){
		scanf("%d" , a+i);
	}
	b.push_back(a[0]);
	repp(i,1,n){
		if(i%2==1){
			b.push_back(a[i]);
		} else {
			b.push_front(a[i]);
		}
	}
	while(!b.empty()){
		if(n%2==0){
			printf("%d" , b.back());
			b.pop_back();
		} else {
			printf("%d" , b.front());
			b.pop_front();
		}
		if(!b.empty()){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
