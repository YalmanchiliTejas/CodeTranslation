n = int(input())
lis = list(map(int,input().split()))
max = 0
count = 0
for i in range(n):
  if max <= lis[i]:
    max = lis[i]
    count += 1
  else:
    pass
  
print(count)