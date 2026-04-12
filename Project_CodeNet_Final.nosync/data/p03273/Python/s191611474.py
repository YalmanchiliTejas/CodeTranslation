h,w = map(int,input().split())
a = [0]*h
for i in range(h):
    a[i] = list(input())
b = []
for i in range(h):
    if a[i] == ["."]*w:
        pass
    else:
        b.append(a[i])
c = [[0 for j in range(w)] for i in range(h)]
for i in range(w):
    sw = 1
    for j in range(len(b)):
        if  b[j][i] == "#":
            sw = 0
            break
    if sw == 0:
        for j in range(len(b)):
            c[j][i] = b[j][i]
for i in range(len(c)):
    for j in range(len(c[0])):
        if c[i][j] != 0:
            print(c[i][j],end="")
    print("")
