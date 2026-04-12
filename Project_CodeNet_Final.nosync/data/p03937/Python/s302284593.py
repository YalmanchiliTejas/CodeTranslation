H, W = map(int, input().split())
AA = [input() for _ in range(H)]

right = 0
for A in AA:
    left = A.index('#')
    if left < right:
        print('Impossible')
        break
    right = W - 1 - A[::-1].index('#')
else:
    print('Possible')
