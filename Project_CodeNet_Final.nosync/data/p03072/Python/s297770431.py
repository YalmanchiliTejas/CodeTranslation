n=int(input())
hl=list(map(int,input().split()))

total=1

for i in range(1,n):
  flag=True
  #print(i)
  for j in range(i):
    #print(j)
    dif=hl[i]-hl[j]
    #print(dif)
    if dif<0:
      flag=False
      break
  if flag:
    total+=1
print(total)