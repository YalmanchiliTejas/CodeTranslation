H, W = map(int, input().split())
cells = []
for _ in range(H):
    a = list(input())
    try:
        idx = a.index('#')
        cells.append(a)
    except:
        pass
# print('cells', cells)
cells = list(zip(*cells))
# print('cells', cells)
ans = []
for cell in cells:
    try:
        idx = cell.index('#')
        ans.append(cell)
    except:
        pass
ans = list(zip(*ans))
# print('ans', ans)
for i in ans:
    print(''.join(i))
