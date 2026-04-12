h,w=map(int,input().split())
a=[]
for i in range(h):
  at=list(str(input()))
  a.append(at)
i=0
j=0
t=0
while True:
  if j!=w-1:
    if a[i][j+1]=="#":
      for k in range(i+1,h):
        if a[k][j]=="#":
          t=1
          break
      else:
        j=j+1
  if i!=h-1:
    if a[i+1][j]=="#":
      for k in range(j+1,w):
        if a[i][k]=="#":
          t=1
          break
      else:
        i=i+1
  if t==1:
    print("Impossible")
    break
  elif i==h-1 and j==w-1:
    print("Possible")
    break