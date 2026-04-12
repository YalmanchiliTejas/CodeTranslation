H, W = map(int, input().split())

A = []
for _ in range(H):
    a = list(input())
    A.append(a)

r = 0
for i in range(H):
    for j in range(r):
        if A[i][j] == '#':
            print('Impossible')
            exit(0)

    flag = False
    for j in range(r+1, W):
        if not(flag):
            if A[i][j] == '#':
                r += 1
            else:
                flag = True
                r = j-1
        else:
            if A[i][j] == '#':
                print('Impossible')
                exit(0)

print('Possible')
