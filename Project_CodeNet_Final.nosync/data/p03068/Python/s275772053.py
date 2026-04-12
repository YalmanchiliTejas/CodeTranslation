n = int(input())
s = str(input())
k = int(input())
x = s[k-1]
s_list = list(s)
str_changed = ''
for i in range(len(s)):
    if s_list[i] != x:
        s_list[i] = '*'
str_changed = "".join(s_list)
print(str_changed)