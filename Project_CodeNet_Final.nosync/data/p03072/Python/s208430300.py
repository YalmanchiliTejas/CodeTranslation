N = int(input())
H = [int(i) for i in input().split()]
count = 0
M = 0

for i in range(N):
  if H[i] >= M:
    count += 1
  M = max(M, H[i])
  
print(count)