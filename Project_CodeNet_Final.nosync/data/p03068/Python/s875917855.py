n = int(input())
string = input()
m = int(input())

target_word = string[m-1]

char_list = []

for i in range(n):
  if target_word == string[i]:
    char_list.append(target_word)
  else:
    char_list.append('*')
    
print(*char_list, sep = '')