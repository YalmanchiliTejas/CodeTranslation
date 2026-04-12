import sys
input = sys.stdin.readline
N = int(input())
table = [0] * 26
mx = 0
a = ord("a")
for c in input()[: -1]:
  table[ord(c) - a] += 1
#print(table)
for _ in range(N - 1):
  s = list(input())[: -1]
  for t in range(26):
    table[t] = min(table[t], s.count(chr(t + a)))

res = []
for c in range(26):
  if table[c]:
    res += [chr(a + c)] * table[c]
print("".join(res))