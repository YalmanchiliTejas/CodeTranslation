n = int(input())
h = list(map(int, input().split()))
count = 1
for i in range(1,n):
  flag = True
  for j in range(i):
    if h[i] < h[j]:
      flag = False
  if flag == True:
    count += 1
print(count)