N = int(input())
H = list(map(int, input().split()))

highest = 0
count = 0

for i in range(N):
  if H[i] >= highest:
    highest = H[i]
    count += 1

print(count)