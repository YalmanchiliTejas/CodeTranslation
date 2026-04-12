N = input()
S = input()
K = input()
c = S[int(K)-1]
r = ''
for t in S:
  if t == c:
    r += c
  else:
    r += '*'

print(r)