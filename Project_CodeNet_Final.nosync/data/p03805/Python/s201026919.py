from itertools import permutations

N, M = map(int, input().split())
gr = set()

for i in range(M):
    a, b = map(int, input().split())
    gr |= {(a-1,b-1),(b-1,a-1)}

ans = 0
for p in permutations(range(N)):
    if p[0]==0:
        cnt = 0
        cntp = 0
        for i in range(N-1):
            cnt += 1
            if (p[i],p[i+1]) in gr:
                cntp += 1
            else:
                break
        if cnt == cntp:
            ans += 1
print(ans)