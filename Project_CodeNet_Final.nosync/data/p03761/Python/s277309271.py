n = int(input())
S = [input() for i in range(n)]
cnt = [[s.count(chr(97 + i)) for i in range(26)] for s in S]
ans = ''
for i in range(26):
  for j in range(min([c[i] for c in cnt])):
    ans += chr(97 + i)
print(ans)