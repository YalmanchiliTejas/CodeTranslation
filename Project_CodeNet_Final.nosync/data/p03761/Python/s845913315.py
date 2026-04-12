N = int(input())

ans = []
for i in range(N):
  char = list(input())
  dct = {chr(i):0 for i in range(97, 97+26)}
  for c in char:
    dct[c] += 1
  ans.append(dct)

dd = {chr(i):50 for i in range(97, 97+26)}
for i in range(len(ans)):
  for j in range(97, 97+26):
    dd[chr(j)] = min(ans[i][chr(j)], dd[chr(j)])

res = ''
for k,v in dd.items():
  res += k * v
res = sorted(res)
print("".join(res))