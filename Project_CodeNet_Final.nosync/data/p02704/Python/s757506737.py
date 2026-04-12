import sys
readline = sys.stdin.readline

def check(k):
    res = [[None]*N for _ in range(N)]
    H = []
    W = []
    for i in range(N):
        if S[i] == 0 and U[i] & (1<<k):
            res[i] = [1]*N
        elif S[i] == 1 and not U[i] & (1<<k):
            res[i] = [0]*N
        else:
            H.append(i)
    for j in range(N):
        if T[j] == 0 and V[j] & (1<<k):
            for i in range(N):
                if res[i][j] == 0:
                    return -1
                res[i][j] = 1
        elif T[j] == 1 and not V[j] & (1<<k):
            for i in range(N):
                if res[i][j] == 1:
                    return -1
                res[i][j] = 0
        else:
            W.append(j)

    for st in range(4):
        if st > 1:
            for i in range(len(H)):
                for j in range(len(W)):
                    h, w = H[i], W[j]
                    res[h][w] = (i+j+st)%2
        else:
            for i in range(len(H)):
                for j in range(len(W)):
                    h, w = H[i], W[j]
                    res[h][w] = st
        flag = True
        for i in H:
            if S[i] == 0:
                cnt = 1
                for j in range(N):
                    cnt &= res[i][j]
                if  (cnt ^ (U[i]>>k)) & 1:
                    flag = False
                    break
            else:
                cnt = 0
                for j in range(N):
                    cnt |= res[i][j]
                if  (cnt ^ (U[i]>>k)) & 1:
                    flag = False
                    break
        else:
            for j in W:
                if T[j] == 0:
                    cnt = 1
                    for i in range(N):
                        cnt &= res[i][j]
                    if  (cnt ^ (V[j]>>k)) & 1:
                        flag = False
                        break
                else:
                    cnt = 0
                    for i in range(N):
                        cnt |= res[i][j]
                    if  (cnt ^ (V[j]>>k)) & 1:
                        flag = False
                        break
        if flag:
            return res
    return -1
    

N = int(readline())
S = list(map(int, readline().split()))
T = list(map(int, readline().split()))
U = list(map(int, readline().split()))
V = list(map(int, readline().split()))

ans = [[0]*N for _ in range(N)]

for k in range(64):
    res = check(k)
    if res == -1:
        ans = -1
        break
    for i in range(N):
        for j in range(N):
            ans[i][j] |= res[i][j]<<k
if ans == -1:
    print(-1)
else:
    print('\n'.join([' '.join(map(str, a)) for a in ans]))
    