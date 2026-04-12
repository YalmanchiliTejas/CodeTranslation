N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(N):
    a.append(a[-1]*2 + 3)
    p.append(p[-1]*2 + 1)
# print(a, p)

def f(lv, x):
    if lv == 0:
        return x
    c = a[lv-1] + 2
    if x == 1:
        return 0
    elif 1 < x < c:
        return f(lv-1, x-1)
    elif x == c:
        return p[lv-1] + 1
    elif c < x < a[lv]:
        return p[lv-1] + 1 + f(lv-1, x-c)
    else:
        return p[lv]

print(f(N, X))