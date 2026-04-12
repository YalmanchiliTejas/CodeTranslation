search_str = "AC"
cur_string = input()
str_len = len(cur_string)
str_list = []
for i in range(str_len-1):
    str_list.append(cur_string[i:i+2])
if search_str in str_list:
    print("Yes")
else:
    print("No")