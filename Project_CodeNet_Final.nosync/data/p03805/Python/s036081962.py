N,M = map(int,input().split())
G = {}
for _ in range(M):
    a,b = map(int,input().split())
    if a not in G:
        G[a] = []
    G[a].append(b)
    if b not in G:
        G[b] = []
    G[b].append(a)
hist = [0 for _ in range(N+1)]
stack = [1]
hist[1] = 1
cnt = 0
F = {}
while stack:
    cur = stack[-1]
    if cur not in F:
        F[cur] = G[cur][:]
        F[cur] = iter(F[cur])
    F1 = list(F[cur])
#     print("cur={},F1={}".format(cur,F1))
    if len(F1)>0:
        F[cur] = iter(F1)
        x = next(F[cur])
        if hist[x]==0:
            stack.append(x)
            hist[x] = 1
        else:
            if sum(hist)==N:
                cnt += 1
                hist[cur]=0
                del F[cur]
                stack.pop()
    else:
#         print("cur={}".format(cur))
#         print("stack={}".format(stack))
        if sum(hist)==N:
            cnt += 1
        hist[cur]=0
        del F[cur]
        stack.pop()
print(cnt)