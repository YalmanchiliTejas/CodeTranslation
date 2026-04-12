N = int(input())
H = list(map(int, input().split()))

count = 0
max_high = 0
for i in range(N):
  if H[i] >= max_high:
    count += 1
    max_high = H[i]

print(count)