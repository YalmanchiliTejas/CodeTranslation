import string
n = int(input())
S = [input() for _ in range(n)]
L = string.ascii_lowercase
ans = ''
for i in L:
  ans += i * min(j.count(i) for j in S)
print(ans)