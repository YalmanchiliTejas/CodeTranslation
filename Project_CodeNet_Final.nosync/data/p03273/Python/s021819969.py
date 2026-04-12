H,W = list(map(int,input().split()))

rows = []
for i in range(1,H+1):
    row = input()
    if row.count("#") > 0:
        rows.append(list(row))

cols = []
for j in range(W):
    col = ""
    for k in range(len(rows)):
        col += rows[k][j]

    if col.count("#") > 0:
        cols.append(col)
        
ans = []
for l in range(len(cols[0])):
    row = ""
    for m in range(len(cols)):
        row += cols[m][l]

    ans.append(row)
    
print("\n".join(ans))