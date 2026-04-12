H, W = map(int, input().split())

field = [list(input()) for _ in range(H)]
count = 0
for i in range(H):
    for j in range(W):
        if field[i][j] == '#':
            count += 1
            
if count <= (H + W - 1):
    print('Possible')
else:
    print('Impossible')
