n = int(input())
start = list(input())
ans = dict()
for i in start:
    if i not in ans:
        ans[i] = 1
    else:
        ans[i] += 1
for i in range(n-1):
    k = dict()
    for j in list(input()):
        if j in k:
            k[j] += 1
        else:
            k[j] = 1
    for j in ans.keys():
        if j in k:
            ans[j] = min(ans[j], k[j])
        else:
            ans[j] = 0
p = ""
for i in ans.keys():
    for j in range(ans[i]):
        p += i
p = list(p)
p.sort()
print("".join(p))