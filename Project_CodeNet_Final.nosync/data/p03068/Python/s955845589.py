N = int(input())
S = input()
K = int(input())
 
moji = S[K-1]
ns = ''
for s in S:
  if moji == s:
    ns += moji
  else:
    ns += '*'
print(ns)