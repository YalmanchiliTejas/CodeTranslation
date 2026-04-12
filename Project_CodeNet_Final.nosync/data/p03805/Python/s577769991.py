n,m = map(int,input().split())
ls = [[int(x) for x in input().split()] for _ in range(m)]
can = [int(x) for x in range(2,n+1)]

import itertools
ans = 0 
for ls_can in list(itertools.permutations(can)):
    ls_can = [1]+list(ls_can)
    flg = 0
    for i in range(n-1):
        if [ls_can[i],ls_can[i+1]] in ls or [ls_can[i+1],ls_can[i]] in ls :
            flg +=1
        else:
            break
        if flg == n-1:
            ans +=1
print(ans)