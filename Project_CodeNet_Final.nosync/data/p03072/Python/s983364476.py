N = int(input())
H = [int(x) for x in input().split()]
count = 0
for i in range(N):
  for j in range(i):
    if H[i] < H[j]:
      break
  else:
      count+=1
print(count)
