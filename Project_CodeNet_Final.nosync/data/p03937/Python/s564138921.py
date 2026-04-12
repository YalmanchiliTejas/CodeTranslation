H,W = map(int,input().split())
A = [input() for i in range(H)]
c = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            c += 1

print('Possible' if c == H+W-1 else 'Impossible')
