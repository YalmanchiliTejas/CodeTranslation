import sys
sys.setrecursionlimit(10**7)
n_ver, n_edge = map(int,input().split())
ad_ls = [[] for _ in range(n_ver)]
for i in range(n_edge):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    ad_ls[a].append(b)
    ad_ls[b].append(a)
done_ls = [0] * n_ver
def dfs(ver):
    done_ls[ver] = 1
    num = 0
    if done_ls == [1] * n_ver:
        done_ls[ver] = 0
        return 1
    for nex in ad_ls[ver]:
        if done_ls[nex]:
            continue
        num += dfs(nex)
    done_ls[ver] = 0
    return num
print(dfs(0))
