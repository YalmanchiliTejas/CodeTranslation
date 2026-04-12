#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 105 ;
int n ;
char s[maxn] ;
int k ;
int a[5] , b[5] ; 
int ans = 0 ;
int q[maxn] , cur = 0 ;
bool f[5] ;
bool judge()
{
	if(b[1] == q[1] && a[1] > s[q[1]] - '0')  return 0 ;
	if(b[1] > q[1] || a[1] < s[q[1]] - '0')  return 1 ;
	if(k == 1)  return 1 ;

    if(cur < 2 && k >= 2)  return 0 ; 
	if(b[2] < q[2])  return 0 ;
	if(b[2] == q[2] && a[2] > s[q[2]] - '0')  return 0 ;
	if(b[2] > q[2] || a[2] < s[q[2]] - '0')  return 1 ;
	if(k == 2)  return 1 ;
	
	if(cur < 3 && k >= 3)  return 0 ; 
	if(b[3] < q[3])  return 0 ;
	if(b[3] == q[3] && a[3] > s[q[3]] - '0')  return 0 ;
	if(b[3] > q[3] || a[3] < s[q[3]] - '0')  return 1 ;
	
	return 1 ;
}
void dfs(int now , int step)
{
	if(now == n)
	{
		if(step < k)  return ;
		if(judge())  ans ++ ;
		return ;
	}
	if(step == k)
	{
		if(judge())  ans ++ ;
		return ;
	}
	for(int i = now + 1 ; i <= n ; i ++)
	  for(int j = 1 ; j <= 9 ; j ++)
	    a[step + 1] = j , b[step + 1] = i , dfs(i , step + 1) ;
}
int main()
{
   scanf("%s" , s + 1) ;
   scanf("%d" , &k) ;
   n = strlen(s + 1) ;
   for(int i = 1 ; i <= n ; i ++)
     if(s[i] > '0')  q[++ cur] = i ;
   dfs(0 , 0) ;	
   printf("%d\n" , ans) ;
   return 0 ;
}