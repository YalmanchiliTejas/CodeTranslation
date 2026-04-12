H, W = map(int, input().split())

a = ["" for i in range(H)]
for i in range(H):
    a[i] = input()

row_deleted = [False for i in range(H)]
col_deleted = [False for i in range(W)]

for i in range(H):
    all_white = True
    for e in a[i]:
        if e != ".":
            all_white = False
    
    if all_white:
        row_deleted[i] = True
    
for i in range(W):
    all_white = True
    for j in range(H):
        if not row_deleted[j] and a[j][i] != ".":
            all_white = False
    
    if all_white:
        col_deleted[i] = True
        
for i in range(H):
    if row_deleted[i]:
        continue
    for j in range(W):
        if col_deleted[j]:
            continue
        print(a[i][j], end = '')
    print("")