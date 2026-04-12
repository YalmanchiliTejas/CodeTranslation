import itertools
N,M = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(M)]
r = list(range(1,N+1))
ok = 1
cnt = 0
for v in itertools.permutations(r):
    if(v[0] == 1):
        ok = 1
        for i in range(N-1):
            if(list(v[i:i+2]) not in ab and list(reversed(v[i:i+2])) not in ab):
                ok = 0
                break
        if(ok == 1):
            cnt += 1
print(cnt)