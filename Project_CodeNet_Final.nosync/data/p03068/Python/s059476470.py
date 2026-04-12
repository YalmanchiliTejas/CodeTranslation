str_len = int(input())
input_str = input()
target_char_num = int(input())
target_char = input_str[target_char_num-1]

#print(str_len,input_str,target_char)

print_str = ''

for i in range(str_len):
  if input_str[i] != target_char:
    print_str = print_str + '*'
  else:
    print_str = print_str + target_char

print(print_str)