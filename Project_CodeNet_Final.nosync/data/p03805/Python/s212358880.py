N, M = list(map(int, input().split()))
ab = {i:[] for i in range(N)}
for _ in range(M):
    a, b = list(map(int, input().split()))
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)
    
cand = [[0]+[one] for one in ab[0]]
while len(cand)>0 and len(cand[0])<N:
    tmp_cand = []
    for c in cand:
        last = c[-1]
        n = []
        for nc in ab[last]:
            if nc not in c:
                n.append(c+[nc])
        tmp_cand.extend(n)
    cand = tmp_cand
print(len(cand))