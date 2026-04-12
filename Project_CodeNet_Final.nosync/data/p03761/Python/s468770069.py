from collections import defaultdict
n = int(input())
Ss = []
for i in range(n):
    tmp = defaultdict(int)
    S = input()
    for s in S: tmp[s] += 1
    Ss.append(tmp)

alpha = 'abcdefghijklmnopqrstuvwxyz'
ans = {}
for s in alpha:
    ans[s] = Ss[0][s]
    for i in range(1,n):
        ans[s] = min(Ss[i][s],ans[s])

for s in alpha:
    if ans[s] != 0: print(s*ans[s],end='')
print()