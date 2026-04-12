n = int(input())
h = []
y = map(int, input().split())

for z in y:
    h.append(z)

v = 1
f = h[0]
for i in range(n):
    if i != 0:
        if f <= h[i]:
            if f < h[i]:
                v += 1
                f = h[i]
            else:
                v += 1

print(v)