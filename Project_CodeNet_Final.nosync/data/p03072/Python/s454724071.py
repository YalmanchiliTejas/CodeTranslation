N = int(input())
H = list(map(int, input().split()))
count = 0
M = 0
for i in range(N):
  if H[i]>=M:
    count += 1
    M = H[i]
print(count)