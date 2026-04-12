import sys
sys.setrecursionlimit(1000000)

N,M = map(int, input().split())
P = [list(map(int, input().split())) for _ in range(M)]

vis_N = [-1]*(N+1)
count = 0
vis_N[1] = 1

def search(a):
    global count,vis_N,vis_Nij
    #print(count,vis_N)
    if sum(vis_N)+1 == N:
        count = count + 1
        return# count#print(count,"A",i)
    
    for i in range(M):
        if (P[i][0] == a and vis_N[P[i][1]] == -1) or (P[i][1] == a and vis_N[P[i][0]] == -1):
            if P[i][0] == a:
                nxt = P[i][1]
            else:
                nxt = P[i][0]
            #vis_N[a] = 1
            vis_N[nxt] = 1
            search(nxt)
            vis_N[nxt] = -1
    
    return# count

search(1)
print(count)