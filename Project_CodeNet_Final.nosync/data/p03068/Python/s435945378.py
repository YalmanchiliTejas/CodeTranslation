N = int(input())
S = input()
K = int(input())
t = ''
for s in S:
  if s != S[K - 1]:
    t += '*'
  else:
    t += s
print(t)