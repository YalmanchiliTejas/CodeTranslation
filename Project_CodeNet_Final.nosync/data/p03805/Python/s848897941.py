"""
順列全探索
"""
import itertools
n, m = map(int, input().split())
path = []
for _ in range(m) :
    a, b = map(int, input().split())
    path.append([a, b])

ans = 0
order_list = list(itertools.permutations(range(2,n+1)))
for order in order_list :
    now = 1
    for i in order :
        if [now,i] in path :
            now = i
        elif [i,now] in path :
            now = i
        else :
            break
    else :
        ans += 1
print(ans)
