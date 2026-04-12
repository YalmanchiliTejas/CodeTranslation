H,W = list(map(int,input().split()))
A = [list(input()) for _ in range(H)]
x = 0
y = 0
A[y][x] = 'x'
while True:
    if x < W-1 and A[y][x+1] == '#':
        x = x+1
        A[y][x] = 'x'
    elif y < H-1 and A[y+1][x] == '#':
        y = y+1
        A[y][x] = 'x'
    elif y < H-1 and A[y+1][x] == '.':
        print('Impossible')
        exit()
    else:
        break
for a in A:
    if '#' in a:
        print('Impossible')
        exit()
print('Possible')