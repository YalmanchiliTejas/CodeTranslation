N,M = map(int,input().split())
K = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    K[a-1].append(b-1)
    K[b-1].append(a-1)

c = 0
P = [0]*N
P[0] = 1
def bfs(start,used):
    global c
    for i in K[start]:
        M = used[:]
        k = 0
        if M[i] == 0:
            M[i] = 1
            for j in M:
                if j != 1:
                    k = 1
                    break
            if k == 0:
                c += 1
            else:
                bfs(i,M)

bfs(0,P)
print(c)