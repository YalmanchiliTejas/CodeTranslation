import itertools

n, m = map(int, input().split())
edge = zeros = [ [0]*n for _ in range(n) ]

for i in range(m):
    s, e = map(int, input().split())
    s -= 1
    e -= 1
    edge[s][e] = 1
    edge[e][s] = 1
    
result = 0

cands= list(itertools.permutations(range(1, n)))

def search(cand):
    cand = [0].extend(cand)
    for i in range(1, n):
        if edge[i-1][i] == 0:
            return False
    return True
for cand in cands:
    result += search(cand)
    
result = 0

cands= list(itertools.permutations(range(1, n)))

def search(cand):
    cand = list(cand)
    cand.insert(0, 0)
    for i in range(1, n):
        if edge[cand[i-1]][cand[i]] == 0:
            return False
    return True
for cand in cands:
    result += search(cand)
    
print(result)