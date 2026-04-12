import sys
a, b, c, x, y = map(int, input().split())
ans=sys.maxsize
for i in range(max(x,y)+1):
  temp=2*c*i
  if x-i>0:
    temp+=a*(x-i)
  if y-i>0:
    temp+=b*(y-i)
  ans=min(ans,temp)

print(ans)