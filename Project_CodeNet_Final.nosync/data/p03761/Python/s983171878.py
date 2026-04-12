n = int(input())
S = [str(input()) for _ in range(n)]
from collections import defaultdict
dic = defaultdict(int)

for s in list(S[0]):
    dic[s] += 1
for s in S[1:]:
    tmp = defaultdict(int)
    for i in list(s):
        tmp[i] += 1
    for j in dic.keys():
        dic[j] = min(dic[j], tmp[j])

ans = []
for d in dic.keys():
    num = dic[d]
    ans += [d]*num

ans.sort()
print(''.join(ans))
