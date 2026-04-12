a,b,c,x,y=map(int,input().split())
ans=float("inf")
for i in range(2*(max(x,y)+1)):
  p=i*c
  p+=max(x-i//2,0)*a
  p+=max(y-i//2,0)*b
  ans=min(p,ans)
print(ans)