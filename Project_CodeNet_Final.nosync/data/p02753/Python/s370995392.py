s = input()
st = s[0]
flag = False
for i in range(1,3):
  if st != s[i]:
    flag = True
    break
if flag:
  print('Yes')
else:
  print('No')