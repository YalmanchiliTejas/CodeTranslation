h, w = map(int, input().split())
A = [str(input()) for _  in range(h)]

q_ = 0
for i in range(h):
    flag = 0
    for j in range(w):
        if A[i][j] == '#' and flag == 0:
            p = j
            q = j
            flag = 1
        elif A[i][j] == '#' and flag == 1:
            q = j
        else:
            pass
    if p < q_:
        print('Impossible')
        exit()
    else:
        q_ = q
else:
    print('Possible')