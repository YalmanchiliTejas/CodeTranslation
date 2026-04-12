from collections import defaultdict

N,M = map(int,input().split())

D = defaultdict(list)

for i in range(M):
    a,b = map(int,input().split())
    D[a].append(b)
    D[b].append(a)

S = [[[1],1]] #Stack 初期はwalked=[1]のnow=1
ans = 0
def dfs(ans,S):
    while(len(S)>0):
        SS = S.pop()
        walked,now = SS[0],SS[1]
        #print(SS)
        for d in D[now]:
            if d not in walked:
                ans = dfs(ans,[[walked+[d],d]])
        if len(walked)==N: return ans+1
    return ans

print(dfs(ans,S))