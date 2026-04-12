h,w = map(int,input().split())
a = [input() for i in range(h)]

flagh = [0]*h
flagw = [0]*w

for i in range(0,h):
    if a[i]=="."*w:
        flagh[i] = 1
    for j in range(0,w):
        if a[i][j] == ".":
            flagw[j] += 1

for i in range(h):
    if flagh[i] != 1:
        for j in range(w):
            if flagw[j] != h:
                print(a[i][j],end="")
        print("")
