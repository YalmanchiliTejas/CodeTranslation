n=int(input())
numlist=list(map(int,input().split()))
count=0
for i in range(n):
  for j in range(i):
    if numlist[i]<numlist[j]:
      break
  else:
    count+=1
print(count)