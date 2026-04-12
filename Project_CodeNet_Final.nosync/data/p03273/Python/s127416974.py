# ABC107B - Grid Compression
h, w = list(map(int, input().rstrip().split()))
data = [input().rstrip() for _ in range(h)]
row = [False] * h
col = [False] * w

for i in range(h):
    for j in range(w):
        if data[i][j] == "#":
            row[i] = True
            col[j] = True

for i in range(h):
    if row[i] == True:
        for j in range(w):
            if col[j] == True:
                print(data[i][j], end="")
        print()