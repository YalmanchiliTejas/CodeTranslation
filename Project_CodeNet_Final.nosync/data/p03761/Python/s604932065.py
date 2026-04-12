from collections import Counter
S = [input() for _ in range(int(input()))]
T = [Counter(s) for s in S]
A = ""
for i in range(ord("a"), ord("z")+1):
  A += chr(i)*min(t[chr(i)] for t in T)
print(A)