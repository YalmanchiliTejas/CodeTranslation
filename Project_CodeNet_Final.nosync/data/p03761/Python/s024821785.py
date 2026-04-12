n = int(input())
S = [input() for i in range(n)]

ref = "abcdefghijklmnopqrstuvwxyz"
out = ""
for i in range(26):
  countmin = []
  for j in range(n):
    countmin.append(S[j].count(ref[i]))
  minnum = min(countmin)
  for k in range(minnum):
    out += ref[i]
print(out)