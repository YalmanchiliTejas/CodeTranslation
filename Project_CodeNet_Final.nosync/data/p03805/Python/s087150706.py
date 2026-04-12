N, M = map(int, input().split())
a, b = [], []

for i in range(M) :
    _a, _b = map(int, input().split())
    
    a.append(_a - 1)
    b.append(_b - 1)

zero_mask = "".join(['0' for x in range(N)])
full_mask = "".join(['1' for x in range(N)])
paths_cnt = 0
paths_set = set()

def do_mask(m, idx) :
    newmask = m[:idx] + '1' + m[idx + 1:]
    return newmask

def dfs(m, idx) :
    global paths_cnt
    
    # print("DBG, do dfs with : ", m, idx)
    # do mask for current idx
    newmask = do_mask(m, idx)
    
    if newmask == full_mask :
        paths_cnt += 1
    else :
        for i in range(N) :
            # print("DBG2 : ", idx != i, newmask[i] != '1', (idx, i) in paths_set, (idx, i))
            if idx != i and newmask[i] != '1' and (idx, i) in paths_set:
                dfs(newmask, i)
# generate map
for i in range(M) :
    paths_set.add((a[i], b[i]))
    paths_set.add((b[i], a[i]))
    
dfs(zero_mask, 0)
print(paths_cnt)