n = int(input())
s = input()
k = int(input())
a = s[k-1]
l = []
for i in range(n):
  if s[i]!=a:
    l.append("*")
  else:
    l.append(a)
print(*l,sep='')
    