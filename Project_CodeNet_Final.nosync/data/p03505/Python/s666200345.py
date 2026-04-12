p,a,b = map(int,input().split())
if(a<=b):
  if(a>=p):
    print(1)
  else:
  	print(-1)
else:
  p-=a
  up=a-b
  if(p<=0):
    print(1)
  else:
  	num=p//up+(p%up!=0)
  	print(num*2+1)
