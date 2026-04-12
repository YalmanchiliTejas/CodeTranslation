n = int(input())
h = list(map(int, input().split()))
max_h = 0
ans = 0
for a in h:
  if max_h <= a:
    ans += 1
  max_h = max(a, max_h)
  
print(ans)