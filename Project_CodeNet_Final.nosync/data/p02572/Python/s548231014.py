n = int(input())
a = list(map(int, input().split()))
sum = 0
ans = 0
for b in a:
  sum = (sum + b) % (10**9+7)
for b in a:
  sum -= b
  ans = (ans + sum * b) % (10**9+7)
print(ans)