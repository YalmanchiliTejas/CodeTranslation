S_list = list(input())


a_flg = 0
b_flg = 0
i = 0
while i < 3:
  if (S_list[i] == "A"):
    a_flg = 1
  else:
    b_flg = 1
  i += 1

if (a_flg == 1 and b_flg ==1):
  print("Yes")
else:
  print("No")
#
