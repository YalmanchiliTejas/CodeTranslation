H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
max_x = 0
max_y = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            if max_x > j or max_y > i:
                print('Impossible')
                exit()
            else:
                max_x = j
                max_y = i
print('Possible')