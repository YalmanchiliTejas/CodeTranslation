n = int(input())
h = list(map(int, input().split()))
a = 1
m = h[0]
for i in range(1, n):
    m = max(h[i-1], m)
    if m <= h[i]:
        a += 1
print(a)
