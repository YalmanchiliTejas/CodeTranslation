H, W, A = open(0).read().split(maxsplit=2)
if A.count('#') == int(H) + int(W) - 1:
    print('Possible')
else:
    print('Impossible')