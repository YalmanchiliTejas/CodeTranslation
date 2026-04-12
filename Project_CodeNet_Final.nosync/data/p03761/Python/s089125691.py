import string
n = int(input())
S = [input() for _ in range(n)]
l = string.ascii_lowercase
ans = ''
for i in l:
  ans += i * min(j.count(i) for j in S)
print(ans)