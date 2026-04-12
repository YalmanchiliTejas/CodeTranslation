from math import ceil
k,a,b=map(int,input().split())
if k<=a:
  print(1)
elif a>b:
  print(1+(k-b-1)//(a-b)*2)
else:
  print(-1)