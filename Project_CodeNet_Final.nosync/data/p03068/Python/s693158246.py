n = int(input())
s = input()
k = int(input())

c = s[k-1]
a = ""
for t in list(s):
 if t == c:
  a += c
 else:
  a += "*"
print(a) 