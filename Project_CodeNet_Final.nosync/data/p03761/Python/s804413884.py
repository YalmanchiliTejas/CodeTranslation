from itertools import groupby, accumulate, product, permutations, combinations
from collections import Counter
def solve():
    N = int(input())
    dics = [0]*N
    S = [input() for _ in range(N)]
    dic = Counter(S[0])
    for i in range(1,N):
        new_dic = Counter(S[i])
        for k in dic.keys():
            if k in new_dic:
                dic[k] = min(dic[k],new_dic[k])
            else:
                dic[k] = 0
    ans = ''
    for k,v in sorted(dic.items()):
        ans += k*v
    return ans
print(solve())