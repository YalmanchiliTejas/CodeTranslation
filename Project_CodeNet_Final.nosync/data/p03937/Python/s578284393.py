H,W = map(int,input().split())
A = [input() for i in range(H)]

x = ms = 0
for i in range(H):
    for j in range(x,W):
        if A[i][j] == '.':
            if i==H-1:
                print('Impossible')
            else:
                break
        else:
            x = j
            ms += 1

cs = sum(row.count('#') for row in A)

print('Possible' if cs==ms else 'Impossible')