N = int(input())
A = list(map(int, input().split()))
ans = 0
hoge = 0
mod = 10**9+7
for i in range(N):
    hoge = hoge + A[i]
    hoge = hoge % mod

for i in range(N):
    hoge = hoge - A[i]
    if hoge < 0:
        hoge = hoge + mod
    ans = ans + A[i] * hoge
    ans = ans % mod

print(ans%mod)
