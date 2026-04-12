length = int(input())
string = input()
K_str_id = int(input())

K_str = string[K_str_id - 1]

output = ""
for tmp_str in string:
    if tmp_str == K_str:
        output += tmp_str
    else:
        output += "*"
print(output)