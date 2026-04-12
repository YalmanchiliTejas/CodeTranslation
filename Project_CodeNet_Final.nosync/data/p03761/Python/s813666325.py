alp = [chr(ord('a') + i) for i in range(26)]
L = [float('inf')]*26
n = int(input())
S = []
ans = ''
for i in range(n):
  S.append(input())
for j in range(n):
  for k in range(26):
    if S[j].count(alp[k]) <= L[k]:
      L[k] = S[j].count(alp[k])
for l in range(26):
  if L[l] != 0:
    for m in range(L[l]):
      ans += alp[l]
print(ans)