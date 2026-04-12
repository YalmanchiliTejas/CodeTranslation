n = int(input())
str = input()
k = int(input())

str_list = list(str)
for i in range(n):
    if str_list[i] != str_list[k - 1]:
        str_list[i] = '*'

str_changed = "".join(str_list)
print(str_changed)
