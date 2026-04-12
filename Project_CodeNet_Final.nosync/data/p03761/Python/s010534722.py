n = int(input())
al=[chr(ord('a') + i) for i in range(26)]
A = [list(input()) for i in range(n)]
ans = ''
for i in range(26):
  st = al[i]
  cn = 50
  for j in range(n):
    cn=min(A[j].count(st),cn)
  ans += st*cn
print(ans)