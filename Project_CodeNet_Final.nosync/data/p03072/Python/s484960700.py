n = int(input())
h = list(map(int, input().split()))
count = 1
res = h[0]
for i in range(1, n):
    if res <= h[i]:
        res = h[i]
        count += 1
print(count)