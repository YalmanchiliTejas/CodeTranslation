n = int(input())
h = [int(i) for i in input().split(" ")]
c = 0

for i in range(0, n):
    f = True
    for j in range(0, i):
        if h[j] > h[i]:
            f = False
            break
    if f:
        c += 1

print(c)