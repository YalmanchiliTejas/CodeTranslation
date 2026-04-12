x = input()
flg = 0
for i in x:
  for j in x:
    if i != j:
      flg = 1
if flg == 1:
  print('Yes')
else:
  print('No')