n=int(input())

a=list(input().split())
total=1
for i in range(1,n):
  flag=0
  for k in range(i):
    if int(a[k])>int(a[i]):
      flag+=1
  if flag==0:
    total+=1
print(total)
      