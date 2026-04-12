n = int(input())
data = list(map(int, input().split()))
count = 1
for i in range(1, n):
  for j in range(i):
    if data[i] < data[j]:
      break
  else:
    count += 1
print(count)