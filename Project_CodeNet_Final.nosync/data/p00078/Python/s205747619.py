def fprint(x):
    if x < 10:
        print("   ",end="")
    elif x < 100:
        print("  ",end="")
    elif x < 1000:
        print(" ",end="")
    print(x,end="")

while True:
    N = int(input())
    if N == 0:
        break

    table = [[0 for i in range(N)] for j in range(N)]

    cnt =  1
    row = N // 2 + 1
    col = N // 2
    table[row][col] = cnt
    while cnt < N*N:
        row = (row + 1) % N
        col = (col + 1) % N
        while table[row][col] != 0:
            row = (row + 1) % N
            col = (col - 1 + N) % N
        cnt += 1
        table[row][col] = cnt

    for i in range(N):
        for j in range(N):
            fprint(table[i][j])
        print("")

