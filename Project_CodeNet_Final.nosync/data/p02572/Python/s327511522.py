n = int(input())
a = [int(x) for x in input().split()]
sum = 0
ans = 0

for e in a:
  sum += e
  
for e in a:
  sum -= e
  ans += e*sum

print(ans%(10**9+7))  