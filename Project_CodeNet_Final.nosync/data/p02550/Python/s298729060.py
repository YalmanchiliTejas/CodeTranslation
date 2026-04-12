
n, x, m = map(int, input().split())

dic = {}
a = x
s = 0
c = m
for i in range(1, n + 1):
    if a not in dic:
        s += a
        dic[a] = [i]
    elif len(dic[a]) == 1:
        s += a * (1 + (n - i) // (i - dic[a][0]))
        dic[a].append(i)
    else:
        break
    a = pow(a, 2, m)
print(s)