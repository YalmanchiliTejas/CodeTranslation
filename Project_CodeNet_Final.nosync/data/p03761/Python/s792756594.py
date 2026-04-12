n = int(input())
s = []
for i in range(n):
    s.append(input())

d = {}
for i in range(n):
    if i==0:
        for j in range(len(s[i])):
            if s[i][j] in d:
                d[s[i][j]] += 1
            else:
                d[s[i][j]] = 1
    else:
        for k in d.keys():
            if d[k] > 0:
                d[k] = min(d[k],s[i].count(k))
ans = ""
for k in d.keys():
    ans += k*d[k]
print("".join(sorted(ans)))

