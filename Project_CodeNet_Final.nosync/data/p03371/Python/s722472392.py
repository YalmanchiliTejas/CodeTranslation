a,b,c,x,y=map(int,input().split())
ans=10**18
for i in range(0,max(x,y)+1):
  tmp=max((x-i),0)*a+max((y-i),0)*b+i*2*c
  ans=min(ans,tmp)
print(min(ans,tmp))