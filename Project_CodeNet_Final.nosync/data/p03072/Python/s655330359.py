N=int(input())
H=list(map(int,input().split()))
answer=0
for i in range(0,N):
  count=0
  for j in range(0,i):
    if H[i]>=H[j]:
      count+=1
  if count==i:
    answer+=1
print(answer)