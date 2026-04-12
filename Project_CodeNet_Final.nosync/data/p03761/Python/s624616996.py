def f(x):
    return ord(x) - ord('a')


base = ord('a')


def g(x):
    return chr(base + x)


n = int(input())

cnt = [[0] * 26 for _ in range(n)]
for i in range(n):
    for c in list(input()):
        cnt[i][f(c)] += 1

res = ''
for i in range(26):
    spam = min([cnt[j][i] for j in range(n)])
    res += g(i)*spam
print(res)