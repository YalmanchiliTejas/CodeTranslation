N = int(input())
MM = input().split()
count1 = 0
for i in range(N):
  count2 = 0
  for j in range(i+1):
    if int(MM[i]) < int(MM[j]):
      count2 +=1
  if count2 == 0:
    count1 +=1
print(count1)