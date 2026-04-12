from collections import Counter
n = int(input())
S = sorted([input() for i in range(n)],key=len)

x = Counter(S.pop(0))
for k,v in x.items():
    for j in S:
        if j.count(k)<v:
            x[k]=j.count(k)

ans_li = []
for k,v in x.items():
    if v!=0:
        ans_li.append(k*v)
print(''.join(sorted(ans_li)))