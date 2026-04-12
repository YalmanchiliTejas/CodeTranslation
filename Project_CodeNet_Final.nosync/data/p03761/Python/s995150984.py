import sys
import collections


def input():
    return sys.stdin.readline()[:-1]


N = int(input())
ans_dic = collections.Counter(list(input()))
for _ in range(N-1):
    c = collections.Counter(list(input()))
    for k, v in ans_dic.items():
        if k in c:
            if ans_dic[k] > c[k]:
                ans_dic[k] = c[k]
        else:
            ans_dic[k] = 0

ans = []
for k, v in ans_dic.items():
    for _ in range(v):
        ans.append(k)

ans.sort()
print(''.join(ans))
