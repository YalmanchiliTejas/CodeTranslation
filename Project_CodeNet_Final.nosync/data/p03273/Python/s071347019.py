H, W = map(int, input().split())
lst = []
for i in range(H):
    lst.append(list(input()))
for i in range(H-1, -1, -1):
    if '#' not in lst[i]:
        del lst[i]
for j in range(W-1, -1, -1):
    cnt = 0
    for i in range(len(lst)):
        if lst[i][j] == '#':
            cnt += 1
    if cnt == 0:
        for i in range(len(lst)):
            del lst[i][j]
for i in lst:
    print(''.join(i))