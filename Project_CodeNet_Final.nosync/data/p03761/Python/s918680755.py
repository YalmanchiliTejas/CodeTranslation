import string

n = int(input())
alpha = string.ascii_lowercase
x = [[] for _ in range(26)]

for _ in range(n):
    s = input()
    for a in alpha:
        x[alpha.index(a)].append(s.count(a))

ans = ""
for i in range(26):
    ans += min(x[i]) * alpha[i]

print(ans)