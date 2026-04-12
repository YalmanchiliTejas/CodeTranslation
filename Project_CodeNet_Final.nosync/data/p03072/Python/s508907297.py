N, *H = map(int, open(0).read().split())
c = 0
for i in range(N):
    b = True
    for j in range(i):
        if H[j] > H[i]:
            b = False
    if b:
        c += 1
print(c)