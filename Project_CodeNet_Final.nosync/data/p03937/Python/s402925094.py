H, W = map(int, input().split())
A = [list('.'+input()+'.') for _ in range(H)]
if sum(A[i].count('#') for i in range(H)) != H + W -1:
    print('Impossible')
    exit()
A.append('.'*(W+2))
A.insert(0, '.'*(W+2))
h, w = 1, 1
for i in range(H+W-2):
    n = []
    for j in [(0,-1), (0,1), (-1,0), (1,0)]:
        if A[h+j[0]][w+j[1]] == '#':
            n.append(j)
    if i == 0 and len(n) != 1 or i > 0 and len(n) != 2:
        print('Impossible')
        exit()
    if i == 0 or hp != h+n[0][0] or wp != w+n[0][1]:
        j = 0
    else:
        j = 1
    hp, wp = h, w
    h, w = h+n[j][0], w+n[j][1]
if h == H and w == W:
    print('Possible')
else:
    print('Impossible')
