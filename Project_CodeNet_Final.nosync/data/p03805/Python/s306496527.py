import itertools
N,M = list(map(int,input().split()))
lis = []
for i in range(N):
    lis.append([i+1])
for i in range(M):
    a,b = list(map(int,input().split()))
    lis[a-1].append(b)
    lis[b-1].append(a)
pemls = [i for i in range(2,N+1)]
lis_root = list(itertools.permutations(pemls,N-1))

counter = 0
for i in range(len(lis_root)):
    now = 1
    step = [1]
    flag = 1
    for j in range(len(lis_root[i])):
        #print("root:"+str(lis_root[i])+ " now:"+str(now) )
        if lis_root[i][j] in lis[now-1]:
            now = lis_root[i][j]
            step.append(now)
        else:
            flag = 0
            break
        if len(step) == N:
            break
    if flag ==1:
        counter += 1
        #print(counter)
print(counter)
