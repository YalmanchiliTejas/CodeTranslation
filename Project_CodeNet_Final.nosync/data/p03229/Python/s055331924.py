#%%
n = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())
a.sort(reverse=True)
ook = []
tii = []
for i in range(0, n//2):
    ook.append(a[i])
for i in range(n//2, n):
    tii.append(a[i])
if n % 2 == 0:
    ans = 2 * (sum(ook) - sum(tii)) - (ook[-1] - tii[0])
    print(ans)
else:
    tmp = tii.pop(0)
    tmp1 = 2 * (sum(ook) - sum(tii)) + (tii[0]) - tmp
    tmp2 = 2 * (sum(ook) - sum(tii)) + tmp - ook[-1]
    print(max(tmp1, tmp2))

