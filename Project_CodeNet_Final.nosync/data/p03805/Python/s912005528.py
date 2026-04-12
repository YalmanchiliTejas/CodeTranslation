# -*- coding: utf-8 -*-
n,m = list(map(int,input().split()))
ab = [list(map(int,input().split())) for i in range(m)]

#逆順にしたもの追加
ab += [[b,a] for a,b in ab]

#辺id付きで、idがfrom,abi[from]=[to1,to2,...] のリスト
abi = [[] for _ in range(n+1)]
for i,(a,b) in enumerate(ab):
    abi[a].append(b)



#再起のlimitを上げる
import sys
sys.setrecursionlimit(4100000)

def dfs(idx=1,visitted=[1],cnt=1):
    ret = 0
    if cnt==n:
        return 1
    for to in abi[idx]:
        if to not in visitted:
            ret += dfs(to,visitted+[to],cnt+1)
    return ret
print(dfs())