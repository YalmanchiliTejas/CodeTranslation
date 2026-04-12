h,w = map(int,input().split())

field = [[s for s in input()] for _ in range(h)]

tmp = ["" for _ in range(w)]
for i in range(h):
    for j in range(w):
        tmp[j] += field[i][j]

row = [s.count("#") == 0 for s in field]
col = [s.count("#") == 0 for s in tmp]

for i,r in enumerate(row):
    for j,c in enumerate(col):
       if not (r or c):
           print(field[i][j],end="")

    print()