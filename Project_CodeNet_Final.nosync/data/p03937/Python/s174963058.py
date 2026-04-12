h, w = map(int, input().split())
c = []
for i in range(h):#h:高さ
    c.append([str(m) for m in list(input())])
pcnt = 0
qcnt = 0
for i in range(h):
    for j in range(w):
        if c[i][j] == "#":
            for p in range(i + 1, h):
                if c[p][j] == "#":
                    pcnt = 1
            for q in range(j + 1, w):
                if c[i][q] == "#":
                    qcnt = 1
            if pcnt == 1 and qcnt == 1:
                print("Impossible")
                exit()
            pcnt = 0
            qcnt = 0
print("Possible")