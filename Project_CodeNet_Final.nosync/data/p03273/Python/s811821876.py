h, w = map(int, input().split())
b = []
li = [0] * w
for i in range(h):
    a = list(input())
    b.append(a)
    for j in range(w):
        if a[j] == "#":
            li[j] += 1

for i in range(h):
    if b[i].count(".") == w:
        continue
    for j in range(w):
        if li[j] != 0:
            print(b[i][j], end="")
    print("")
