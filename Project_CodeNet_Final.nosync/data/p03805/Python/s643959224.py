import itertools
N,M=map(int,input().split())
L=[]
c=[i for i in range(1,N+1)]
for _ in range(M):
    x,y = map(int,input().split())
    l1 = [x,y]
    l2 = [y,x]
    L.append(l1)
    L.append(l2)
c = [list(x) for x in itertools.permutations(c)]
count = 0
ans = 0
for x in c:
    if x[0] > 1:
        break
#    print(x)
    for i in range(N-1):
        if [x[i],x[i+1]] in L:
            count += 1
 #           print(x[i],x[i+1])
            if count == N - 1:
                ans += 1
                count = 0
        else:
            count = 0
            break

print(ans)
