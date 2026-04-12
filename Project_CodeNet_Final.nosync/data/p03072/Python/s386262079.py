n = int(input())
h = list(map(int, input().split()))
c = 1
m = h[0]

for i in range(1, n):
    if h[i] >= m:
        c += 1
        m = h[i]
print(c)
