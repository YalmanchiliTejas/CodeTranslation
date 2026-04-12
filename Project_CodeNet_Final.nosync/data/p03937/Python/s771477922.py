h, w = map(int, input().split())
A = [str(input()) for _ in range(h)]

min_ = 0
max_ = 0
for i in range(h):
    flag = 1
    for j in range(w):
        if flag == 1 and A[i][j] == '#':
            min_ = j
            if min_ < max_:
                print('Impossible')
                exit()
            flag = 0
        if flag == 0 and A[i][j] == '#':
            max_ = j
else:
    print('Possible')
