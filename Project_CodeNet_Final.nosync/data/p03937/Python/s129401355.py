h,w=map(int,input().split())
s = [input() for i in range(h)]
a=0
for i in s:
  a+=i.count("#")
if a==h+w-1:
  print("Possible")
else:
  print("Impossible")