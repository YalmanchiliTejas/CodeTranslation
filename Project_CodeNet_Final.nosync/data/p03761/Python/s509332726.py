from collections import Counter
n = int(input())
S = []

for i in range(n):
    s=input()
    S.append(s)
    if i==0:
        res=Counter(list(s))
    else:
        c=Counter(list(s))
        for key in res.keys():
            if key in c.keys():
                res[key] = min(res[key], c[key])
            else:
                res[key] = 0
#print(res)
for key in sorted(res.keys()):
    if res[key]>0:
        print(key*res[key],end='')
print('')

