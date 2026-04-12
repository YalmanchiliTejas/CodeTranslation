h,w = map(int, input().split())
a=[input() for i in range(h)]

b = []
for i in range(h):
    if a[i]!="."*w:
        b.append(a[i])

c = ["" for i in range(len(b))]

for i in range(w):
    for j in range(len(b)):
        if b[j][i] != ".":
            for k in range(len(b)):
                c[k] += b[k][i]
            break


for i in range(len(c)):
    print(c[i])