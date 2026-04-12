import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int,input().split()))
mod = 10**9 + 7

B = [A[0]]
for i in range(1, n):
    B.append((B[-1] + A[i]) % mod)

ans = 0
for i in range(n-1,0,-1):
    ans = (ans + B[i-1] * A[i])
print(ans%mod)