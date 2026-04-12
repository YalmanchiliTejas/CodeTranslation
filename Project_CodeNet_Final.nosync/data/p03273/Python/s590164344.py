h,w = map(int, input().split())
row = [False]*h
line = [False]*w
a = []
for i in range(h):
    A = input()
    a.append(A)

for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            row[i] = True
            line[j] = True

for i in range(h):
    if row[i]:
        for j in range(w):
            if line[j]:
                print(a[i][j], end = "")
        print()
