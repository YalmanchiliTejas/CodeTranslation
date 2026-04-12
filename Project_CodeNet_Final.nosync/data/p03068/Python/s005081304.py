n = input()
s = input()
k = input()
n = int(n)
k = int(k)
a = str(s[k-1])
for i in s:
  if i != a:
    s = s.replace(i,"*")
print(s)