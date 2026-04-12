n=int(input())
h=list(map(int,input().split()))
count=0
tmp=0
for i in range(n):
  for j in range(i):
    if h[i]<h[j]:
      tmp=1
      break
  if tmp==0:
  	count+=1
  tmp=0
print(count)