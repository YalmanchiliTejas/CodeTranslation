N, M = map(int, input().split())
R = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    R[a - 1].append(b - 1)
    R[b - 1].append(a - 1)
Parents = [[] for i in range(N)]
C = 0

def func(x, c):
    global C
    c += 1
    last = True
    for r in R[x]:
        if r in Parents[x]:
            continue
        for i in range(len(Parents[x])):
            Parents[r].append(Parents[x][i])
        Parents[r].append(x)
        last = False
        func(r, c)
        for i in range(len(Parents[x])):
            Parents[r].remove(Parents[x][i])
        Parents[r].remove(x)
    if last:
        if c == N:
            C += 1

func(0, 0)
print(C)