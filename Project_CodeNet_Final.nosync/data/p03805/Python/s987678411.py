import itertools
N,M = map(int,input().split())
adj = [[0] * (N) for i in range(N)]
for m in range(M):
    a,b = map(int,input().split())
    adj[a-1][b-1] = 1
    adj[b-1][a-1] = 1

ans = 0

for i in itertools.permutations(range(2,N+1)):
    f = 0
    #print(i)
    for n in range(0,N-2):
        #print(i[n]-1,i[n+1]-1)
        if adj[0][i[0]-1] != 1:
            f = 1
            break
        if adj[i[n]-1][i[n+1]-1] != 1:
            #print(adj[i[n]-1][i[n+1]-1])
            f = 1
            break
    if f == 0:
        #print(i)
        ans += 1
print(ans)