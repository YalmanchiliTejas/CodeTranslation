n = int(input())
h = [int(i) for i in input().split()]
c = 0
m = 0
for i in range(n):
    if h[i] >= m:
        c += 1
        m = h[i]
print(c)