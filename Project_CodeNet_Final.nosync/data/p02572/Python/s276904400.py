n = int(input())
a = list(map(int, input().split()))

s = sum(a)
b = 10**9+7
ans = 0
for i in a:
  s -= i
  ans += i*(s%b)
  ans %= b
print(ans)