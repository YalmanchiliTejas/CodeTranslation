H, W = map(int, input().split())
A = [''] * H
for i in range(H):
    A[i] = input()
x, y = 0, 0
while True:
    if (x < H-1 and A[x+1][y] == '#') and (y < W-1 and A[x][y+1] == '#'):
        print('Impossible')
        exit()
    elif (x > 0 and A[x-1][y] == '#') and (y > 0 and A[x][y-1] == '#'):
        print('Impossible')
        exit()
    elif x == H-1 and y == W-1:
            print('Possible')
            exit()
    elif (x == H-1 or A[x+1][y] == '.') and (y == W-1 or A[x][y+1] == '.'):
        print('Impossible')
        exit()
    elif x < H-1 and A[x+1][y] == '#':
        x += 1
        continue
    elif y < W-1 and A[x][y+1] == '#':
        y += 1
        continue