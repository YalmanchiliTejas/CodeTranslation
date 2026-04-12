n = int(input())
s = [list(input()) for _ in range(n)]

from collections import Counter
ans = Counter(s[0])

for i in range(1,n):
    can = Counter(s[i])
    for j in ans.keys():
        ans[j]= min(ans[j],can[j])

ans = sorted(ans.items(),key=lambda x:x[0])

ls = []
for i in range(len(ans)):
    if ans[i][1]!=0:
        l = [ans[i][0] for _ in range(ans[i][1])]
        ls += l

print("".join(ls))