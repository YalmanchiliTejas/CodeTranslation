H,W = [int(i) for i in input().split()]
li = [list(input()) for _ in range(H)]

flag = 0
for i in range(H):
    tmp = []
    for j,k in enumerate(li[i]):
        if k == '#':
            tmp.append(j)
    if i != 0 and p != tmp[0]:
        flag = 1
        break
    p = tmp[-1]

print(['Possible', 'Impossible'][flag])
