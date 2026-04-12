N,M = map(int,input().split())
a = [ list(input()) for i in range(N) ]

t = 0
for i in range(N):
    for j in range(M):
        if a[i][j] == "#":
            if t <= j:
                t = j
            else:
                print("Impossible")
                exit()
print("Possible")
