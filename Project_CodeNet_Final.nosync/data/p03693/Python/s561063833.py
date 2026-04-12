a,b,c=map(int,input().split())
tmp=a*100+b*10+c
if tmp%4==0:
  print("YES")
else:
  print("NO")