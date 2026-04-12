N = int(input())
s = []
for i in range(N):
    val = sorted(input())
    s.append(val)

an = 0
for i in range(N):
    if len(s[an]) <= len(s[i]):
        continue
    else:
        an = i

a = s[an]

for i in range(N):
    n = 0
    while a != s[i] and n < len(a) and n < len(s[i]):
        if a[n] == s[i][n]:
            n += 1
        else:
            if a[n] > s[i][n]:
                s[i].pop(n)
            else:
                a.pop(n)
    if len(a) > len(s[i]):
        a = s[i]

print(''.join(a))