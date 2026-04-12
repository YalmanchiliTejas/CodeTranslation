import sys
readline = sys.stdin.readline
write = sys.stdout.write
def solve():
    N = int(readline())
    if N == 0:
        return False
    x = N//2; y = x+1
    P = [[-1]*N for i in range(N)]
    c = 0
    N2 = N*N
    while c < N2:
        if P[y][x] == -1:
            c += 1
            P[y][x] = c
            x = (x + 1) % N; y = (y + 1) % N
        else:
            x = (x - 1) % N; y = (y + 1) % N
    for line in P:
        write("".join(map("{:4d}".format, line)))
        write("\n")
    return True
while solve():
    ...
