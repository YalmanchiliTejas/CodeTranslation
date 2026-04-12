a,b,c=map(int, input().split())
a=a*100
b=b*10
if (a+b+c)%4==0:
  print("YES")
else:
  print("NO")
  