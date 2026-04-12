
n = int(input())

doc = {}
for i in range(n):
    s = input()
    if i == 0:
        for j in range(len(s)):
            doc[s[j]] = doc.get(s[j], 0) + 1
        dockeys = list(doc.keys()).sort()
    else:
        tmp = {}
        for j in range(len(s)):
            tmp[s[j]] = tmp.get(s[j], 0) + 1
        dockeys = list(doc.keys())
        for k in dockeys:
            doc[k] = min(doc[k], tmp.get(k, 0))



ans = ""
dockeys = list(doc.keys())
dockeys.sort()

for k in dockeys:
    ans += k*doc[k]

print(ans)