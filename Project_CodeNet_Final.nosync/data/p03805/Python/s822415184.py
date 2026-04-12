N, M = map(int, input().split())
paths = set()

for i in range(M) :
    _f, _t = map(int, input().split())
    paths.add((_f - 1, _t - 1))
    paths.add((_t - 1, _f - 1))

zeromask = "".join(['0' for x in range(N)])
fullmask = "".join(['1' for x in range(N)])
cnt = 0

def do_mask(m, idx) :
    return m[:idx] + '1' + m[idx + 1:]

def dfs(m, idx) :
    global cnt
    new_mask = do_mask(m, idx)
    
    if new_mask == fullmask :
        cnt += 1
    else :
        for i in range(N) :
            if i != idx and m[idx] != '1' and (idx, i) in paths:
                dfs(new_mask, i)
            
dfs(zeromask, 0)
print(cnt)