s = input()
flg = False
for i in range(1, len(s)):
  if s[i-1] == 'A' and s[i] == 'C':
    flg = True
    break
if flg:
  print('Yes')
else:
  print('No')