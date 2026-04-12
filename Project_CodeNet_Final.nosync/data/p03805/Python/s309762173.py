n, m = map(int, input().split())
paths = set()

zero_mask = "".join(["0" for x in range(n)])
full_mask = "".join(["1" for x in range(n)])

paths_cnt = 0

for i in range(m) :
    _a, _b = map(int, input().split())
    paths.add((_a - 1, _b - 1))
    paths.add((_b - 1, _a - 1))

def mask_idx(s, idx) :
    newmask = s[:idx] + "1" + s[idx + 1:] 
    return newmask 

def dfs(cur_idx, mask) :
    
    global paths_cnt
    new_mask = mask_idx(mask, cur_idx)
    # print("DBG : ", cur_idx, new_mask, full_mask)
    
    if new_mask == full_mask :
        paths_cnt += 1
    for i in range(n) : 
        if i != cur_idx and new_mask[i] != '1' and (cur_idx, i) in paths:
            dfs(i, new_mask)
            
dfs(0, zero_mask)
print(paths_cnt)
    