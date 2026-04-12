n, x, m = map(int, input().split())

ai = x
i = 0

memo = []
d = {}
tmp = 0

while True:
    if ai in d:
        break
    d[ai] = i
    memo.append(ai)

    ai = (ai ** 2) % m
    i += 1

s = d[ai]
e = i
su = sum(memo[s:])

if n <= e+1:
    print(sum(memo[0:n]))
else:
    zan = n - s
    ans = sum(memo[:s]) + (zan // (e-s)) * su
    if zan % (e-s):
        ans += sum(memo[s:s+(zan % (e-s))])
    print(ans)


