N = int(input())
H = [int(e) for e in input().split()]

count = 0
for i in range(N):
  FL = 0
  for j in range(i):
    if H[i]<H[j]:
      FL = 1
  if FL == 0:
    count += 1

print(count)