from collections import Counter
n = int(input())
S = [None] * n
for i in range(n):
  S[i] = Counter(input())
s = ''
for i in range(26):
  cnt = 50
  for j in range(n):
    cnt = min(S[j][chr(97 + i)], cnt)
  s += chr(97 + i) * cnt
print(s)