n, x, m = map(int, input().split())

ans = []
c = [0]*m
flag = False
for i in range(n):
    if c[x] == 1:
        flag = True
        break
    ans.append(x)
    c[x] = 1
    x = x**2 % m
if flag:
    p = ans.index(x)
    l = len(ans) - p
    d, e = divmod(n-p, l)
    print(sum(ans[:p]) + d*sum(ans[p:]) + sum(ans[p:p+e]))
else:
    print(sum(ans))
