n = int(input())
s = input()
k = int(input())
l = []
for i in s:
  if i == s[k - 1]:
    l.append(s[k - 1])
  else:
    l.append("*")
print(*l, sep="")