#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)      //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++) //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)    //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))        //array size
#define SORTD(a) sort(a,a+ASIZE(a),greater<int>()) //sort in descending order for array
#define SORTA(a) sort(a,a+ASIZE(a))                //sort in ascending order for array
#define SORTS(a) sort(a.begin(),a.end())           //sort in ascending order for string type
typedef long long LL;
typedef unsigned int UINT;
 
void SCAN(int *a){scanf("%d",a);}                             //scan for type int
void SCAN(int *a,int n){int i;REP(i,n){scanf("%d",&a[i]);}}   //scan for type int array
void SCAN(UINT *a){scanf("%u",a);}                            //scan for type unsigned int
void SCAN(UINT *a,int n){int i;REP(i,n){scanf("%u",&a[i]);}}  //scan for type unsigned int array
void SCAN(LL *a){scanf("%lld",a);}                            //scan for type long long int
void SCAN(LL *a,int n){int i;REP(i,n){scanf("%lld",&a[i]);}}  //scan for type long long int array
void SCAN(char *c){scanf(" %c",c);}                           //scan for type char
void SCAN(char *c,int n){int i;REP(i,n){scanf(" %c",&c[i]);}} //scan for type char array
 
const int MOD = 1000000007;
const int INF = 1000000000;
 
const int DX4[4]= {-1,0,0,1};
const int DY4[4]= {0,-1,1,0};
 
//fill an N-dimensional array with val
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
	fill((T*)array,(T*)(array+N),val);
}
 
int pascalTri(int n,int r){
	int tri[n+1][n+1];
	int i,j;
	REP(i,n+1){REP(j,n+1){tri[i][j]=0;}}
	REP(i,n+1){
		REP(j,n+1){
			if(j>i){break;}
			if(j==0||j==i){tri[i][j]=1;}else{tri[i][j]=(tri[i-1][j-1]%MOD+tri[i-1][j]%MOD)%MOD;}
		}
	}
	return tri[n][r];
}
 
 
int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int x,y,z;
	int i,j;
	
	SCAN(&x);SCAN(&y);SCAN(&z);

 	printf("%d\n",(x-z)/(y+z));
	return 0;
}