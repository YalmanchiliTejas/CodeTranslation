#include<stdio.h>
#include <iomanip>
#include <assert.h>
#include<math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
 size_t strlen(const char *s);
#define rep(i,n) for(int i=0;i<n;i++)
#define SOA(array) (sizeof(array)/sizeof(array[0]))

using namespace std;
std::vector<int> graph[10050];//graph頂点数のsize
const int N=200010;
const int P=998244353;
//比較
long long int compare_int(const void *a, const void *b)
{
    return *(long long int*)a - *(long long int*)b;//a-b昇順
}
//絶対値
int ze(int a, int b){
	if(a>b){
		return a-b;
	}else{
		return b-a;
	}
}
//小さい方
long long int min(long long int a,long long int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}
// a^n mod 
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod 
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

//mod掛け算
long long mt(long long a, long long b, long long mod){
	return (a*b)%mod;
}
//配列最小値　mine(array, SOA(array));
long long int mine(const long long int* array, size_t size)
{
    assert(array != NULL);
    assert(size >= 1);

    long long int min = array[0];
    for (size_t i = 1; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}
//メモ
//	cout<<(n-2)*180<<endl;
//	string s="hoge";
//	cout<<ans<<endl;
//	int  n  ,a  ,b  ,c  ,d  ,e  ,f  ;
//	cin  >>n  >>a  >>b  >>c  >>d  >>e  >>f  ;

/*
	memset(b, '\0', sizeof(b));
初期化*/


/*
	len = strlen(s);
文字列長さ*/


/*
	string s;
	s.size()
*/


/*ソート
	qsort(array, 10, sizeof(int), compare_int);
*/


/*
	char s[N];
	strlen(s)
/*
	if(  <  )puts("Yes");
	else puts("No");
*/
/*文字列比較
if(strcmp(name[i],s)==0)
*/
/*
	graph[a].push_back(b);//graph[a][i番目に入れた]==b
	graph[j].size()	//forで回すときとか

*/
/* クイックソート */
long long int pou(long long int x, long long int y){
	if(y==0){
		return 1;
	}else{
		return pou(x, y-1)*x;
	}
}

void swap (long long int *x,long long  int *y) {
  long long int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

//i<j?
/* クイックソート */
bool hikaku(long long int i, long long int j, long long int hairetsu0[],long long int hairetsu1[]){
	bool ans=true;
	if(hairetsu0[i]==0&&hairetsu0[j]==0){
		if(hairetsu1[i]>=hairetsu1[j]){
			ans=false;
		}
	}else{
		if((hairetsu1[i]+1)*hairetsu0[j]>=(hairetsu1[j]+1)*hairetsu0[i]){
			ans=false;
		}
	}
	return ans;
}
/* クイックソート */
long long int partition (long long int array[], long long int left,long long  int right, long long int hairetsu0[],long long int hairetsu1[]) {
  long long int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left;   // 先頭要素をpivotとする

  do {
//    do { i++; } while (array[i] < array[pivot]);
    do { i++; } while (hikaku(i, pivot, hairetsu0, hairetsu1));
//      do { j--; } while (array[pivot] < array[j]);
    // pivotより小さいものを左へ、大きいものを右へ
      do { j--; } while (hikaku(pivot, j, hairetsu0, hairetsu1));
     if (i < j) { swap(&array[i], &array[j]); }
  } while (i < j);

  swap(&array[pivot], &array[j]);   //pivotを更新

  return j;
}

/* クイックソート */
void quick_sort (long long int array[],long long  int left,long long  int right, long long int hairetsu0[],long long int hairetsu1[]) {
  long long int pivot;

  if (left < right) {
    pivot = partition(array, left, right, hairetsu0, hairetsu1);
    quick_sort(array, left, pivot-1, hairetsu0, hairetsu1);   // pivotを境に再帰的にクイックソート
    quick_sort(array, pivot+1, right, hairetsu0, hairetsu1);
  }
}

int main(){
    long long int n, s;
    long long int a[3010];
    cin>>n>>s;
    a[0]=0;
    rep(i, n){
        cin>>a[i+1];
//        puts("hoge");
    }
    long long int ans=0;
    long long int dp[3010][3010];
    rep(i, n+1){
        rep(j, 3010){
            if(i==0){
                dp[i][j]=0;
            }else{
                if(j<a[i]){
                    dp[i][j]=dp[i-1][j];
                }else if(j==a[i]){
                    dp[i][j]=(dp[i-1][j]+i)%P;
                }else{
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%P;
                }
            }
        }
        ans=(ans+mt(dp[i][s],n-i+1,P))%P;
        dp[i][s]=0;
//        puts("hoge");
    }
    cout<<ans<<endl;
}