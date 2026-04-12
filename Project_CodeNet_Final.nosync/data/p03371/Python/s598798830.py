a,b,c,x,y=map(int,input().split())

loop=max(x*2,y*2)+1
ans=10**9

for i in range(loop):
  ab=i//2
  if x-ab>=0 and y-ab>=0:
    ans=min(ans,a*(x-ab)+b*(y-ab)+c*i)
  if x>=ab and y<ab:
    ans=min(ans,a*(x-ab)+c*i)
  if x<ab and y>=ab:
    ans=min(ans,b*(y-ab)+c*i)
  if x<ab and y<ab:
    ans=min(ans,c*i)
print(ans)