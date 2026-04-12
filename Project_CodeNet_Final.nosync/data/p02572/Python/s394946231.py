mod = 10**9+7
n = int(input())
num = list(map(int,input().split()))
ans = 0
s = sum(num)

for i in num:
  s -= i
  ans += i*s
print(ans%mod)