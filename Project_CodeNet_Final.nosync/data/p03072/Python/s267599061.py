n = int(input())
h = list(map(int, input().split()))
c = 1
max = h[0]
for i in range(1, n):
    if max <= h[i]:
        c += 1
        max = h[i]
print(c)