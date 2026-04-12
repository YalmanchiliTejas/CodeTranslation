n = int(input())
S = [input() for i in range(n)]
cnt = [[s.count(chr(97 + i)) for i in range(26)] for s in S]
ans = ''
for i in range(26):
  ans += chr(97 + i) * min([c[i] for c in cnt])
print(ans)