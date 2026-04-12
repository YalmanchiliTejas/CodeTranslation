n = int(input())
s = input()
k = int(input()) - 1
a = ""
for i in range(n):
  if s[i] != s[k]:
    a = a +"*"
  else:
    a = a + s[i]
print(a)