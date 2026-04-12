H, W = map(int, input().split())
white_column = []
a = [list(input()) for _ in range(H)]

# Mark white columns
for j in range(W-1, -1, -1):
    flag = True

    for i in range(H):
        if a[i][j] != '.':
            flag = False
            break

    if flag:
        for i in range(H):
            a[i].pop(j)
        W -= 1

# Print line if it contains black grid
for i in range(H):
    flag = True

    for j in range(W):
        if a[i][j] == '.':
            continue
        else:
            flag = False
            break

    if flag:
        continue
    else:
        print(''.join(a[i]))