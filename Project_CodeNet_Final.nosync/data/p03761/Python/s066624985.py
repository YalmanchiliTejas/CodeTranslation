from collections import Counter,defaultdict
n = int(input())

dic = {}
dicjudge = {}
for i in range(n):
    C = Counter(input())
    for j in C:
        if not j in dic:
            dic[j] = C[j]
        elif dic[j] > C[j]:
            dic[j] = C[j]

        if j in dicjudge:
            dicjudge[j] += 1
        else:
            dicjudge[j] = 1

anslst = sorted(dic.items())
#print(anslst)

ans = ''
for i in anslst:
    if dicjudge[i[0]] >= n:
        ans += i[0] * i[1]
print(ans)

