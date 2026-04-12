n = int(input())
h = list(map(int, input().split()))

max_ = h[0]
res = 1
for i in range(1, n):
    if max_ <= h[i]:
        max_ = h[i]
        res += 1
print(res)
