n = int(input())
s = []
for i in range(n):
    s.append(sorted(input()))

l = []
for i in range(len(s[0])):
    a = s[0][i]
    f = True
    for j in range(1, len(s)):
        if not (a in s[j]):
            f = False
            break
    if f:
        l.append(a)
        for j in range(1, len(s)):
            s[j].remove(a)
print("".join(l))