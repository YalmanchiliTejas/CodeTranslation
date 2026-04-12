
h, w = map(int, input().split())

a = [""] * h
for i in range(h):
    a[i] = list(input())

row = [False] * w
col = [False] * h

for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            row[j] = True
            col[i] = True

for i in range(h):
    if col[i] == True:
        for j in range(w):
            if row[j] == True:
                print(a[i][j], end = "")

        print() 
