h,w=map(int,input().split())
v=sum(sum(1 for i in input() if i=="#") for _ in range(h))
if v==h+w-1:
  print("Possible")
else:
  print("Impossible")
