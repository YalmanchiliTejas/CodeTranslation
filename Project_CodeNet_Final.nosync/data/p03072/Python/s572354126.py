n = int(input())
h = [int(x) for x in input().split()]
o = 0
m = h[0]
for i, x in enumerate(h):
    if i == 0:
        o += 1
    else:
        if x >= m:
            m = x
            o += 1
print(o)