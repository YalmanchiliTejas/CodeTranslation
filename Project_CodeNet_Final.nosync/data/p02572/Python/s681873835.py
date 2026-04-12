MOD = 10 ** 9 + 7

n = int(input())
a = list(map(int, input().split()))

s = sum(a) % MOD
ans = 0

for i in a:
  s-=i
  s%=MOD
  ans+=s*i
  ans%=MOD

print(ans)