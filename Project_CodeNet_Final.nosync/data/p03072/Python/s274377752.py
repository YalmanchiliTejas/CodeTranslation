n = int(input())
h = input().split()
c = 1
aux = False
h = list(map(int, h))
for i in range(1,n):
    for j in range(i - 1, -1, -1):
        if h[j] <= h[i]:
            aux = True
        else:
            aux = False
            break
    if aux:
        c = c + 1
        aux = 0

print(c)