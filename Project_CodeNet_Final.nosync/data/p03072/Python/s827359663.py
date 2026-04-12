n = int(input())
hh = list(map(int, input().split()))

x = 1
for i in range(1, n):
    f = True
    for j in range(i):
        if hh[j] > hh[i]:
            f = False
            break
    if f:
        x += 1
print(x)
