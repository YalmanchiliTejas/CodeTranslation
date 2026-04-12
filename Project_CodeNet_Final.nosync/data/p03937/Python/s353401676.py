h, w = map(int, input().split())
A = [list(str(input())) for _ in range(h)]

p = -1
q = -1
for i in range(h):
    for j in range(w):
        if A[i][j] == '#':
            if q > j:
                print('Impossible')
                exit()
            else:
                p = j
    q = p
else:
    print('Possible')
