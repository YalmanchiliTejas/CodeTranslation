from itertools import permutations
N,M = map(int,input().split())
ab = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]
c = permutations(range(N)[1:])
ans = 0
for per in c:
    per = [0] + list(per)
    flag = True
    for i in range(N-1):
        p1 = min(per[i],per[i+1])
        p2 = max(per[i],per[i+1])
        if (p1,p2) in ab:
            continue
        else:
            flag=False
    if flag:
        ans+=1
print(ans)