n = int(input())

h = list(map(int, input().split()))

maxHeight = 0
count = 0

for i in range(n):
    count += 1 if maxHeight <= h[i] else 0
    maxHeight = max(h[i], maxHeight)

print(count)