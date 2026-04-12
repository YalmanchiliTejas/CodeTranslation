n = int(input())
*l, = map(int,input().split())
ans = 0
for i in [0]*n:
  if max(l) == l[-1]:
    ans += 1
  del l[-1]
print(ans)