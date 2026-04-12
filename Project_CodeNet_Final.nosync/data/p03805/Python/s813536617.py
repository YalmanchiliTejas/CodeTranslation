from itertools import permutations
def check(i,j):
    if j==N-2 and x[j] in G[i]:
        return True
    if x[j] in G[i]:
        return check(x[j],j+1)
    return False
    
N,M = map(int,input().split())
G = {i:[] for i in range(1,N+1)}
for _ in range(M):
    a,b = map(int,input().split())
    G[a].append(b)
    G[b].append(a)
cnt = 0
for x in permutations(range(2,N+1),N-1):
    if check(1,0):
        cnt += 1
print(cnt)   