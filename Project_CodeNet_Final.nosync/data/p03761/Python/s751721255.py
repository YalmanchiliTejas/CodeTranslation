import string

n = int(input())
s = [input() for _ in range(n)]
l = string.ascii_lowercase
count = {}
ans = ''

for i in l:
    ans += i * min(j.count(i) for j in s)

print(ans)