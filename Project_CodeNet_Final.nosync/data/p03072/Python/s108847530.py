input() #n
ans = hmax = 0
 
for h in map(int, input().split()):
  if hmax <= h:
    hmax = h
    ans += 1
print(ans)