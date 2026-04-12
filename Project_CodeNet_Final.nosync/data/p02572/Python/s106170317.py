import sys; input = sys.stdin.readline
mod = int(1e9)+7
n = int(input())
lis = list(map(int, input().split()))
pre = [0]*n
pre[0] = lis[0]
for i in range(1, n): pre[i] = pre[i-1] + lis[i]
ans = 0
for i in range(1, n): ans = (ans + (lis[i-1]*(pre[n-1] - pre[i-1]))%mod)%mod
print(ans)