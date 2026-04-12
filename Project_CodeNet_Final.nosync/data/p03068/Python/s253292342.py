N = int(input())
S = input()
K = int(input())


target_str = S[K-1]

out = ''
for s in S:
  if s != target_str:
    tmp = '*'
  else:
    tmp = s

  out += tmp

print(out)
