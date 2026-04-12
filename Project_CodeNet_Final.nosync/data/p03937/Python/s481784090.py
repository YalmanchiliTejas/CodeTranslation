def solve():
    H, W = map(int, input().split())
    A = [[i for i in input()] for _ in range(H)]
    
    x, y = 0, 0
    A[y][x] = '.'
    while True:
        if 0 <= x+1 < W and 0 <= y < H and A[y][x+1] == '#':
            x=x+1
            A[y][x] = '.'
        elif 0 <= x < W and 0 <= y+1 < H and A[y+1][x] == '#':
            y=y+1
            A[y][x] = '.'
        else:
            break
    
    for row in A:
        if '#' in row:
            return 'Impossible'

    return 'Possible' if x == W-1 and y == H-1 else 'Impossible'

print(solve())