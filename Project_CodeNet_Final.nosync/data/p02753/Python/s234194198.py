str = input()
str_list = list(str)
 
if str_list[0] != str_list[1]:
  print("Yes")
elif str_list[1] != str_list[2]:
  print("Yes")
else:
  print("No")