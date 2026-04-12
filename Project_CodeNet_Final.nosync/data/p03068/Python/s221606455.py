n = int(input())
s = input()
k = int(input())

str_list = list(s)
x = str_list[k-1]
for i in range(len(s)):
    if str_list[i] != x:
        str_list[i] = "*"
str_changed = "".join(str_list)
print(str_changed)