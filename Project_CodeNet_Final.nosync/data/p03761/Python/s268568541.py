n = int(input())

s = [input() for _ in range(n)]

def f(a, b):
    if len(a) > len(b):
        a, b = b, a
    c = ""
    for i in range(len(a)):
        if a[i] in b:
            idx = b.index(a[i])
            b = b[:idx] + b[idx + 1:]
            c += a[i]
    return c

a = s[0]

for i in range(n):
    b = s[i]
    c = f(a, b)
    a = c

ans = ""
for ch in sorted(list(a)):
    ans += ch

print(ans)
