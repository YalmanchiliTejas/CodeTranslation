n = int(input())
d = {}
for i in range(26):
    c = chr(i+ord('a'))
    d[c] = 10**18

for i in range(n):
    s = str(input())
    de = {}
    for i in range(26):
        c = chr(i+ord('a'))
        de[c] = 0
    for j in range(len(s)):
        if s[j] not in de:
            de[s[j]] = 1
        else:
            de[s[j]] += 1
    for k, v in de.items():
        d[k] = min(d[k], de[k])

d = sorted(d.items())
#print(d)
ans = ''
for k, v in d:
    ans += k*v
print(ans)
