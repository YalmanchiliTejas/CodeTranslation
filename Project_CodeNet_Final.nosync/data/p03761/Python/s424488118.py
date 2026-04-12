n = int(input())
L = []
for i in range(n):
    L.append(input())

ans = ''
for i in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ':
    tmp = []
    for j in range(n):
        tmp.append(L[j].count(i))
    ans += i * min(tmp)
print(ans)
