from sys import stdin
input = stdin.readline

N, X, M = map(int, input().split())

ls = []
s = set([])

a = X
s.add(a)
ls.append(a)
ind = -1
new_ls = []

while True:
    a = pow(a, 2, M)

    if a in s:
        ind = ls.index(a)
        break
    elif len(ls) == N:
        break
    else:
        s.add(a)
        ls.append(a)

if ind != -1:
    new_ls = ls[ind:len(ls)]

ans = sum(ls)

if len(new_ls) != 0:
    ans += sum(new_ls) * (max(0, (N - len(ls))) // len(new_ls))

    tmp = max(0, (N - len(ls))) % len(new_ls)

    if tmp != 0:
        for i in range(tmp):
            ans += new_ls[i % len(new_ls)]

print(ans)
