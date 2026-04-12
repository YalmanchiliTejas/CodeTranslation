N, M = map(int, input().split())
a = []
b = []
for i in range(M):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

graf = [[] for i in range(N)]

for i in range(M):
    graf[a[i] - 1].append(b[i] - 1)
    graf[b[i] - 1].append(a[i] - 1)

cnt = 0

def sarch(v, graf_check):
    global cnt
    check = list(graf_check)
    check[v] = 1
    #print(v, graf_check)
    if sum(check) == N:
        cnt += 1
    else:
        for i in graf[v]:
            if graf_check[i] == 0:
                sarch(i, check)
                
sarch(0, [0 for i in range(N)])
print(cnt)
