n = int(input())
array1 = list(map(int,input().split()))
counter = 0
for i in range(n):
  j = 0
  while j <= i and array1[i] >= array1[j]:
    if i == j:
      counter += 1
    j += 1
print(counter)
  