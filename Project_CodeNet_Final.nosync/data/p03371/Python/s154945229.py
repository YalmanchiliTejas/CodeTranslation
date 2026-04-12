a,b,c,x,y=map(int,input().split())
if 2*c>=a+b:
  print(a*x+b*y)
else:
  ans=min(x,y)*c*2
  if x<=y:
    ans+=(y-x)*min(b,2*c)
  else:
    ans+=(x-y)*min(a,2*c)
  print(ans)
      
