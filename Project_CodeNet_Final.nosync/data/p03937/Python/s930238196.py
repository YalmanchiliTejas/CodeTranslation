H, W = map(int, input().split())
A = [input() for _ in range(H)]
x = 0
for h in range(H):
    if '#' in A[h][:x]:
        print('Impossible')
        exit()
    if A[h][x] != '#':
        print('Impossible')
        exit()
    while x+1 < W and A[h][x+1] == '#':
        x += 1

    if '#' in A[h][x+1:]:
        print('Impossible')
        exit()

print('Possible')
