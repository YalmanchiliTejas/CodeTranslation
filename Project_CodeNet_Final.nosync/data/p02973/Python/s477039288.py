from bisect import bisect_left

N=int(input())

dp=[-2]*(N+1)
dp[N]=-1

for _ in range(N):
    a=int(input())
    dp[bisect_left(dp,a)-1]=a

print(N-bisect_left(dp,0)+1)
