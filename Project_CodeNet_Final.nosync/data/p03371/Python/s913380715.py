a,b,c,x,y=map(int,input().split())

ans=10**9
for i in range(2*max(x,y)+1):
  s=max(x-i//2,0)
  t=max(y-i//2,0)
  t_ans=s*a+t*b+i*c
  ans=min(ans,t_ans)

print(ans)