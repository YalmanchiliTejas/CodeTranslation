N = int(input())
l = list(map(int, input().split()))

h = l[0]
c = 0
for i in range(N):
  for j in range(i+1):
    if l[i] < l[j]:
      break
    if j == i:
      c += 1
print(c)