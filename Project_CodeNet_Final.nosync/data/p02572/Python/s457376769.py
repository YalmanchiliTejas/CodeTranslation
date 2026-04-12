n = int(input())
s = list(map(int, input().split()))

ans= 0
total = sum(s)

for i in range(len(s)-1):
  total -= s[i]
  ans += total * s[i]

print(ans % (10**9 +7))