n = int(input())
h = list(map(int,input().split()))
c = 0
for i in range(n):
    if h[i] >= h[0]:
        c += 1
        h[0] = h[i]
print(c)