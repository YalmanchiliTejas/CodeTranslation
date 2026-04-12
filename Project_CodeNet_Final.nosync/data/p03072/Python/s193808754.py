n = int(input())
h = [int(i) for i in input().split()]
c = 0
for i in range(n):
    d = 0
    for j in range(0,i + 1):
        if h[i] >= h[j]:
            d += 1
    if d == i + 1:
        c += 1
print(c)            
