n = input()
s = list(raw_input())
k = input()

for i in range(len(s)):
 if s[i] != s[k-1]:
  s[i] = "*"

print "".join(s)