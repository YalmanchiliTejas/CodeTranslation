n = int(input())
sstr = input()
k = int(input())


s = list(sstr)

for i in range(n):
 if s[k-1] != s[i]:
  s[i] = "*"


sStr = "".join(s)
print(sStr)