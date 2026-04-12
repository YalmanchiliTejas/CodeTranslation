from itertools import groupby, accumulate, product, permutations, combinations
from collections import Counter
def solve():
    N = int(input())
    dics = [[0]*N for _ in range(26)]
    S = [input() for _ in range(N)]
    for i in range(N):
        for s in S[i]:
            dics[ord(s)-ord('a')][i]+=1
    ans = ''
    for i in range(26):
        ans += chr(i+ord('a'))*min(dics[i])
    return ans
print(solve())
