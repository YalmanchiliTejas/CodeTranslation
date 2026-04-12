h,w = map(int, input().split())
a = [list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        a[i][j] = [a[i][j], False]

for i in range(h):
    count = 0
    for j in range(w):
        if a[i][j][0] == ".":
            count += 1
    if count == w:
        for j in range(w):
            a[i][j][1] = True

for i in range(w):
    count = 0
    for j in range(h):
        if a[j][i][0] == ".":
            count += 1
    if count == h:
        for j in range(h):
            a[j][i][1] = True

for i in a:
    flag = False
    for j in i:
        if not j[1]:
            print(j[0],end = "")
            flag = True
    if flag:
        print("")