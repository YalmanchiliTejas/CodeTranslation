n = int(input())
s = input()

k = int(input())
for r in s:
  print(r if r == s[k-1] else "*",end="")