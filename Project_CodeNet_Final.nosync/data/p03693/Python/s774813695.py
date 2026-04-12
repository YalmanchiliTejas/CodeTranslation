r,g,b=map(int,input().split())
t=100*r+10*g+1*b
if t%4==0:
  print("YES")
else:
  print("NO")