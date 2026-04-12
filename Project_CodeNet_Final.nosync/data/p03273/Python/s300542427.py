h,w = map(int, input().split())
field = []
for _ in range(h):
    field.append(input())

# 黒がある行を抽出
hasb_row = []
for hi in range(h):
    for wj in range(w):
        if field[hi][wj] == "#":
            hasb_row.append(hi)
            break

# 黒がある列を抽出
hasb_col = []
for wj in range(w):
    for hi in range(h):
        if field[hi][wj] == "#":
            hasb_col.append(wj)
            break
        
# 再構成
f_ans = [[] for _ in range(len(hasb_row))]
for i, hi in enumerate(hasb_row):
    for j, wj in enumerate(hasb_col):
        f_ans[i].append(field[hi][wj:wj+1])
        
for hi in range(len(hasb_row)):
    print("".join(f_ans[hi]))
