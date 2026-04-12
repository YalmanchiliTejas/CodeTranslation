N = int(input())

lis=list(map(int,input().split()))

ans = 0

for ind in range(len(lis)):
  flag = True
  if ind == 0:
    ans += 1
    continue
  for j in range(ind):
      if lis[j] > lis[ind]: 
        flag = False
  if flag:
    ans +=1  
print(ans)