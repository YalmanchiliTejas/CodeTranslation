H, W = map(int, input().split())
table = [input() for _ in range(H)]
path_length = sum([t.count('#') for t in table])
if path_length == H + W - 1:
    print('Possible')
else:
    print('Impossible')