n=int(input())
l=list(map(int,input().split()))
c=1
for i in range(1,n):
  b=True
  for j in range(0,i):
    if l[j]>l[i]:
      b=False
  if b:
    c+=1
print(c)