H, W = map(int, input().split())
As =[input() for _ in range(H)]
cnt = 0
for i in range(H):
    for j in range(W):
        if As[i][j] == '#':
            cnt += 1
if cnt == H+W-1:
    print('Possible')
else:
    print('Impossible')
