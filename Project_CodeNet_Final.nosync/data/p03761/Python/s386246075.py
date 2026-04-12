N = int(input())
S = [input() for n in range(N)]
W = 'abcdefghijklmnopqrstuvwxyz'
ret = ''
for w in W:
  c = min([s.count(w) for s in S])
  if c:
    ret += w * c
print(ret)