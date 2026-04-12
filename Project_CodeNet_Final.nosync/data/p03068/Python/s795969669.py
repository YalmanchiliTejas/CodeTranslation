_ = input()
s = input()
k = int(input())

ss = ''

for a in s:
 if a == s[k-1]:
  ss += s[k-1]
 else:
  ss += '*'
else:
 print(ss)