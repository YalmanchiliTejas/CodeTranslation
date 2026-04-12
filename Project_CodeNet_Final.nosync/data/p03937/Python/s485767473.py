import sys

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

H, W = rl()
A = [list(rs()) for _ in range(H)]

for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            A[i][j] = 1
        else:
            A[i][j] = 0
    A[i].append(0)            
A.append([0] * (W + 1))
bool = True

for i in range(H):
    for j in range(W):
        if i == 0 and j == 0:
            if A[i+1][j] + A[i][j+1] != 1:
                bool = False
            continue
        if i == H - 1 and j == W - 1:
            if A[i-1][j] + A[i][j-1] != 1:
                bool = False
            continue
        if A[i][j] == 1:
            if A[i+1][j] + A[i][j+1] != 1:
                bool = False
            if A[i-1][j] + A[i][j-1] != 1:
                bool = False

print('Possible' if bool else 'Impossible')