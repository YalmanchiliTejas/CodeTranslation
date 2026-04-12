N = int(input())
S = input()
K = int(input())
skey = S[K-1]
t = ""
for s in S:
  if s != skey:
    t += "*"
  else:
    t += s
print(t)