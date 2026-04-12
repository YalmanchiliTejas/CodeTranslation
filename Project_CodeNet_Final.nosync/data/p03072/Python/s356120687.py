n = int(input())
h = list(map(int, input().split()))

count = 1
max = 0
for i in range(n-1):
    if max < h[i]:
        max = h[i]

    if max <= h[i+1]:
        count += 1

print(count)
