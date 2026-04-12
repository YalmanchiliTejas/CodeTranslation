a,b,c=map(int,input().split())
N=a*100+b*10+c
if(N%4==0):
  print("YES")
else:
  print("NO")