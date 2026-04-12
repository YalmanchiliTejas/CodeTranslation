n = int(input())
s = input()
k = int(input())

ss = []
for i in range(n):
  if s[i] != s[k-1]:
    ss.append('*')
  else:
    ss.append(s[i])
print(''.join(ss))
