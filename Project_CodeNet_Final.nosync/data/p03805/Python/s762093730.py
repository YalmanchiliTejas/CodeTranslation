N, M = map(int, input().split())

V = [[] for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    V[a-1].append(b-1)
    V[b-1].append(a-1)
    
Log = [0]*N

def DFS(now_V, now_Log, ans):
    #print(now_V, now_Log, ans, sum(now_Log))
    
    if sum(now_Log)==N:
        ans = ans+1
        #print('cc')
        return ans
    
    for i in V[now_V]:
        if now_Log[i]<1:
            now_Log[i]=1
            ans = DFS(i, now_Log, ans)
            now_Log[i]=0
    
    return ans
          

count = 0  

Log[0] = 1

print(DFS(0, Log, count))