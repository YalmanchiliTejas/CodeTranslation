n=int(input())
m=[]
m.append(int(input()))
count=1
for i in range(n-1):
  k=int(input())
  if k<=m[-1]:
    m.append(k)
    count+=1
  else:
    r=count-1
    l=0
    while l+1<r:
      try1=(r+l)//2
      if m[try1]>=k:
        l=try1
      else:
        r=try1
    if m[l]>=k:
      m[r]=k
    else:
      m[l]=k
print(count)