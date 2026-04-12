h, w = map(int, input().split())
ans = []

# 行チェック
for hi in range(h):
    row = [s for s in input()]
    # 行が全て白だと追加しない
    if row.count('.') == w:
        continue
    else:
        ans.append(row)

# 列チェック
removeindex = []
for wi in range(w):
    blnRem = True
    for row in ans:
        if row[wi] == '#':
            blnRem = False
            break
    if blnRem:
        removeindex.append(wi)

# 表示
for row in ans:
    for i, col in enumerate(row):
        if i in removeindex:
            continue
        print(col, end='')
    print()
