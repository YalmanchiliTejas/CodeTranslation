a,b,c = map(int,input().split())

a=a*100
b=b*10

num = a+b+c

if num%4==0:
  print("YES")
else:
  print("NO")