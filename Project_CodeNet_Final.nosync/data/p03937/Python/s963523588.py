H, W = map(int, input().split())
pos = 0
for _ in range(H):
    row = input()
    for c in row[:pos]:
        if c == '#':
            print('Impossible')
            exit()
    for i in range(pos, W):
        if row[i] == '#':
            pos = i
        else:
            break
    for c in row[pos + 1:]:
        if c == '#':
            print('Impossible')
            exit()
if pos + 1 == W:
    print('Possible')
else:
    print('Impossible')