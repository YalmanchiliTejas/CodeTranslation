N = int(input())
H = list(map(int,input().split()))
count = 1
for i in range(1,N):
  judge = 0
  for j in range(i):
    if(H[j]>H[i]):
      judge = judge +1
      break
  if(judge==0):
    count=count+1
print(count)
  
  
  
  