import numpy as np
N = int(input())
A = list(map(int, input().split()))
B = [0] * (N+1)  # 累積和テーブル B[i] = sum(A[:i])
mod = 10**9 + 7
ans = 0

for i in range(N):
    B[i+1] = B[i] + A[i]  # 累積和

for i in range(N):
    sum = (B[N] - B[i+1]) % mod
    ans += A[i] * sum
    ans %= mod

print(int(ans))