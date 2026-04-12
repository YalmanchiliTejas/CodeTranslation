H, W = map(int, input().split())
A = [[] for i in range(H+2)]
for i in range(H):
    A[i+1] = list(input())
    A[i+1].insert(0,'.')
    A[i+1].append('.')

A[0] = list('.' * (W+2))
A[H+1] = list('.' * (W+2))

for i in range(H+2):
    A[i] = ''.join(A[i])
    #print(A[i])



check = 0

for i in range(1,H+1):
    for j in range(1, W+1):
        if i == 1 and j ==1 :
            if A[i][j] == '#':
                if A[i+1][j] == '.' and A[i][j+1] == '#':
                    pass
                elif A[i+1][j] == '#' and A[i][j+1] == '.':
                    pass
                else:
                    check = 1
                pass
            else:
                check = 1

        elif i == H and j ==W :
            if A[i][j] == '#':
                if A[i-1][j] == '.' and A[i][j-1] == '#':
                    pass
                elif A[i-1][j] == '#' and A[i][j-1] == '.':
                    pass
                else:
                    check = 1
                pass
            else:
                check = 1

        else:
            if A[i][j] == '#':
                if A[i+1][j] == '.' and A[i][j+1] == '#' and A[i-1][j] == '.' and A[i][j-1] == '#':
                    pass
                elif A[i+1][j] == '#' and A[i][j+1] == '.' and A[i-1][j] == '.' and A[i][j-1] == '#':
                    pass
                elif A[i+1][j] == '.' and A[i][j+1] == '#' and A[i-1][j] == '#' and A[i][j-1] == '.':
                    pass
                elif A[i+1][j] == '#' and A[i][j+1] == '.' and A[i-1][j] == '#' and A[i][j-1] == '.':
                    pass
                else:
                    check = 1

if check == 0:
    print('Possible')
else:
    print('Impossible')
