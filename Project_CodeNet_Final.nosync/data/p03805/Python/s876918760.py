n, m = map(int, input().split())
paths = set()

for i in range(m) :
    _a, _b = map(int, input().split())
    paths.add((_a - 1, _b - 1))
    paths.add((_b - 1, _a - 1))

full_mask = "".join(["1" for x in range(n)])
zero_mask = "".join(["0" for x in range(n)])
p_cnt = 0

def dfs(cur_idx, mask) :
    global p_cnt
    
    # set mask and do traverse
    new_mask = list(mask)
    new_mask[cur_idx] = "1"
    new_mask = "".join(new_mask)

    # print("DBG : ", cur_idx, new_mask, full_mask, new_mask == full_mask)
    
    if new_mask == full_mask :
        p_cnt += 1
    else :
        for i in range(n) :
            # if cur_idx -> i in set and i not traversed yet..
            if (cur_idx, i) in paths and mask[i] != "1" :
                dfs(i, new_mask)

dfs(0, zero_mask)
print(p_cnt)
    
            
        