from itertools import permutations
N,M = map(int,input().split())
G = {i:[] for i in range(1,N+1)}
for _ in range(M):
    a,b = map(int,input().split())
    G[a].append(b)
    G[b].append(a)
cnt = 0
for x in permutations(range(2,N+1),N-1):
    flag = 0
    for i in range(N-1):
        if i==0:
            if x[0] in G[1]:continue
            else:
                flag = 1
                break
        if x[i] in G[x[i-1]]:continue
        else:
            flag = 1
            break
    if flag==0:
        cnt += 1
print(cnt)