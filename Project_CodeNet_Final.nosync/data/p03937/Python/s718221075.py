H, W = map(int, input().split(' '))
maps = [input().count('#') for _ in range(H)]
if sum(maps) == H + W - 1:
    print('Possible')
else:
    print('Impossible')
