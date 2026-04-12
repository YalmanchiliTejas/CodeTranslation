a,b,c,x,y=map(int,input().split())

ans=10**9
for i in range(0,max(x,y)*2+2,2):
  tx=max(x-i//2,0)
  ty=max(y-i//2,0)
  t_ans=tx*a+ty*b+i*c
  ans=min(ans,t_ans)
print(ans)