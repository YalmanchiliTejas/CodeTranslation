import itertools

N,M = map(int,input().split())
Data = []
for _ in range(N+1):
    Data.append([0]*(N+1))
for _ in range(M):
    a,b = map(int,input().split())
    Data[a][b] = 1
    Data[b][a] = 1

ans = 0
for r in itertools.permutations(range(2,N+1)):
    Rlist = list(r)
    a = 1
    b = Rlist[0]
    if Data[a][b] == 0:
        continue
    else:
        flag = True 
        for i in range(len(Rlist)-1):
            a = Rlist[i]
            b = Rlist[i+1]
            if Data[a][b] == 0:
                flag = False
                break
        if flag:
            ans += 1

print(ans)
