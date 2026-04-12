n = int(input())
s = list(input())
k = int(input())
q = ''
ans = s[k-1]
for i, w in enumerate(s):
    if not w == ans:
        s[i] = '*'

for x in s:
    q += x
print(q)
