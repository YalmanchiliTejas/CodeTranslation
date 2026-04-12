N = int(input())
S = input()
K = int(input())

mask = S[K-1]

ret = []
for s in S:
  if s == mask:
    ret.append(s)
  else:
    ret.append('*')

print(''.join(ret))
