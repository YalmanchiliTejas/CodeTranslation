n = int(input())
s = input()
k = int(input())

v = s[k-1]

ary = []

for i in s:
  if i != v:
    ary.append('*')
  else:
    ary.append(v)
print (''.join(ary))
