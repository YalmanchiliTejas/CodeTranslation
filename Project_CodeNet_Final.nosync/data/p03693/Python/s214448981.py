a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
if ((100*a+10*b+c)%4)==0:
  print("YES")
else:
  print("NO")