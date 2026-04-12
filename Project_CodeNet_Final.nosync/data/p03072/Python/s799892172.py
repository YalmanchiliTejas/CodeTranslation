n = int(input())
h = list(map(int, input().split()))
count = 1
hi = h[0]
for i in range(1, n):
    if hi <= h[i]:
        hi = h[i]
        count += 1
print(count)
