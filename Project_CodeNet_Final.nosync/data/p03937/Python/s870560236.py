h, w = map(int, input().split())
L = [input() for _ in range(h)]
r = 0
for i in range(h):
    for j in range(w):
        if L[i][j] == '#':
            if j < r:
                print('Impossible')
                exit()
            else:
                r = j
else:
    print('Possible')
