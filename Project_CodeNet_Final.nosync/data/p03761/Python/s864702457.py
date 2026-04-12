n = int(input())
s = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
t = [input() for i in range(n)]
p = []
for i in range(n):
    p.append(sorted(list(t[i])))
st = [51 for i in range(len(s))]

for i in range(len(s)):
    for j in range(n):
        cnt = 0
        for k in range(len(p[j])):
            if p[j][k] == s[i]:
                cnt += 1
        st[i] = min(st[i], cnt)
for i in range(len(st)):
    if st[i] == 51:
        st[i] = 0
for i in range(len(s)):
    for j in range(st[i]):
       print(s[i], end='')
print()