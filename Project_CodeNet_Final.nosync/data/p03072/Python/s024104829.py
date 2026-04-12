n=int(input())
x=list(map(int,input().split()))
count=1
for i in range(1,n):
  xcount=0
  for j in range(0,i):
    if x[i] < x[j]:
      xcount=1
  if xcount == 0:
    count+=1
print(count)  