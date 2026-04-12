input()
hs = list(map(int, input().split()))
c = 0
for i in range(0, len(hs)):
    b = 1
    for j in range(0, i):
        if hs[j] > hs[i]:
            b = 0
    if b == 1:
        c += 1
print(c)