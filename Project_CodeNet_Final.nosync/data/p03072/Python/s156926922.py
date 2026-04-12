n = int(input())
hs = list(map(int,input().split()))
ans = 0
m = 0
for h in hs:
  if m <= h:
    ans += 1
  m = max(m, h)
 
print(ans)
