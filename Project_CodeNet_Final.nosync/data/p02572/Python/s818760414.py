import math
n  = int(input())
arr = list(map(int , input().split()))
pre =[0]*(n+1)
mod = 10**9+7
pre[0]=arr[0]
for i in range(1 , n):
	pre[i]=pre[i-1]+arr[i]
	pre[i]=pre[i]%mod
ans = 0
for i in range(0 , n):
	ans = ans + (arr[i])*(pre[n-1]-pre[i])
	ans = ans%mod
print(ans)