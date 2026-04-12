n = int(input())
char = input()
k = int(input()) - 1

char_list = list(char)

replace = char_list[k]

result = ""

for i in char_list:
    if i==replace:
        result += replace
    else:
        result += "*"

print(result)