a=int(input())
str_list=[str(input()) for i in range(a)]
x=[]
for i in range(len(str_list[0])):
  check=True;
  for j in range(1,a):
    if str_list[0][i] in str_list[j]:
      str_list[j] = str_list[j].replace(str_list[0][i],'',1);
    else:
      check=False;
  if check:
    x.append(str_list[0][i])
if len(x) > 0:
  print(''.join(sorted(x)))
else:
  print('')