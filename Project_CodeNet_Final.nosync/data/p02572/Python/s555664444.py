N = int(input())
a = list(map(int, input().split()))
s = 0
res = 0
m = 10**9+7
for ai in a:
  res += (s * ai) % m
  s += ai

print(res % m)

