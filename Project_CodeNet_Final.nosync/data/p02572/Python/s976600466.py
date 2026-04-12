n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

ans = 0

for aa in a:
  ans += aa
  ans %= mod
ans *= ans
ans %= mod
for aa in a:
  ans -= aa*aa
  ans %= mod


if ans%2 == 1:
  print((ans+mod)//2)
else:
  ans //= 2
  print(ans)	