from collections import defaultdict
n = int(input())
chars = [input() for _ in range(n)]
set_chars = set(chars[0])
d = defaultdict(lambda: 10**10)

# 候補となる文字を先に用意
for char in chars[1:]:
    set_chars = set_chars.intersection(set(char))


for i in range(n):
    for c in set(chars[i]):
        if c not in set_chars:
            continue
        cnt = chars[i].count(c)
        if cnt < d[c]:
            d[c] = cnt

s = ''
for c in 'abcdefghijklmnopqrstuvwxyz':
    if c in d:
        s += c * d[c]
print(s)
