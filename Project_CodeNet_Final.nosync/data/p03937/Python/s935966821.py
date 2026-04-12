h,w=map(int,input().split())
a=[input() for _ in range(h)]

count=0

for i in range(h):
  k=a[i]
  for j in range(w):
    if k[j]=="#":
      count+=1

if count==(h-1)+(w-1)+1:
  print("Possible")
else:
  print("Impossible")