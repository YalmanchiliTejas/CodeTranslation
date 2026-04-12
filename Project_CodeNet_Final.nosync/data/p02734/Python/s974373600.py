import sys
input = sys.stdin.readline
n, s = map(int,input().split())
A = list(map(int,input().split()))
mod = 998244353

ans = 0
B = [0] * (s+1)
for i in range(n):
    for j in range(s, -1, -1):
        if j-A[i] >= 0:
            B[j] = (B[j] + B[j-A[i]])%mod
    if A[i] < len(B):
        B[A[i]] += i+1
    ans = (ans + B[s])%mod#*(n-i)
    # B[s] = 0
    # print(B)
print(ans)