n = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

summ = 0
quadsum = 0

for k in range(n):
    summ = (summ + A[k]) % mod
    quadsum = (quadsum + A[k]*A[k])%mod

ans = (summ*summ)%mod - quadsum
if ans % 2 == 1:
    ans += mod
ans = (ans/2)%mod
print(int(ans))