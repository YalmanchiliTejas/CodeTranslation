h,w = map(int,input().split())
e = []
for i in range(h):
    e.append(list(input()))
rey = [0 for i in range(h)]
rex = [0 for i in range(w)]
for i in range(h):
    count = 0
    for j in range(w):
        if e[i][j] == ".":
            count += 1
    if count == w:
        rey[i] = 1

for i in range(w):
    count = 0
    for j in range(h):
        if e[j][i] == ".":
            count += 1
    if count == h:
        rex[i] = 1

for i in range(h):
    if rey[i]:
        continue
    else:
        for j in range(w):
            if rex[j]:
                continue
            else:
                print(e[i][j],end="")
    print()