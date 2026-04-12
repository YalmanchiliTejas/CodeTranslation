n = int(input())
s = [list(input()) for _ in range(n)]

min_len = float('inf')
short_s =[]
for i in range(n):
  if min_len>len(s[i]):
    min_len = len(s[i])
    for j in range(len(s[i])):
      short_s.append(s[i][j])

c = []
for i in range(len(short_s)):
  if all(short_s[i] in s[j] for j in range(n)):
    for k in range(n):
      s[k].remove(short_s[i])
    c.append(short_s[i])

ans = "".join(sorted(c))
print(ans)