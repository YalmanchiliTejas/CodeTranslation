a, b, c, x, y = map(int, input().split())
#a, b, c, x, y = 1500, 2000, 500, 90000, 100000
#na, nb, nc = x, y, 0
mx = 10**18
for i in range(0, max(x,y)*2+1):
  if i%2==1: continue
  total = max(a*(x-i//2), 0) + max(b*(y-i//2), 0) + c*i
  if total<mx:
    mx=total

print(mx)
