n = int(input())
hList = list(map(int,input().split()))

count = 0
for i in range(n):
  count += 1
  for j in range(i):
    if hList[i] < hList[j]:
      count -= 1
      break
     
print(count)
