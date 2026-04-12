from itertools import groupby, accumulate, product, permutations, combinations
N = int(input())
dics = [[0]*N for _ in range(26)]
for i in range(N):
    S = input()
    for s in S:
        dics[ord(s)-ord('a')][i]+=1
ans = ''
for i in range(26):
    ans += chr(i+ord('a'))*min(dics[i])
print(ans)