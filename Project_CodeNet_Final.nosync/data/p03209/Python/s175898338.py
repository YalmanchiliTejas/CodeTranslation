N, X = map(int, input().split())

L = [1]
P = [1]

for i in range(N):
    tmp = 2*L[i]+3
    L.append(tmp)
    tmp = 2*P[i]+1
    P.append(tmp)

def Heap(now_L, Goal):
    if now_L == 0:
        if Goal <= 0:
            return 0
        else:
            return 1
    elif Goal < L[now_L-1] + 2:
        return Heap(now_L-1, Goal-1)
    else:
        return P[now_L-1] + 1 + Heap(now_L-1, Goal-L[now_L-1]-2)
    
print(Heap(N, X))