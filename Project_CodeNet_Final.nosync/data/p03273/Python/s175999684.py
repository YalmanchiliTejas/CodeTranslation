H, W = map(int, input().split())
h = []
w = []
a = [""]*H
for i in range(H):
    a[i] = input()


for y in range(H):
    flag = True
    for x in range(W):
        if a[y][x] == "#":
            flag = False
            break
    if flag:
        h.append(y)

for x in range(W):
    flag = True
    for y in range(H):
        if a[y][x] == "#":
            flag = False
            break
    if flag:
        w.append(x)

for y in range(H):
    for x in range(W):
        if y not in h and x not in w:
            print(a[y][x], end="")
    if y not in h:
        print()
