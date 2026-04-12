h, w = map(int, input().split())
T = [input() for _ in range(h)]
flagRow = [0] * h
flagColumn = [0] * w

for i in range(h):
    for j in range(w):
        if T[i][j] == "#":
            flagRow[i] = 1
            flagColumn[j] = 1

for i in range(h):
    if flagRow[i] == 1:
        for j in range(w):
            if flagColumn[j] == 1:
                print(T[i][j], end = "")
        print("")