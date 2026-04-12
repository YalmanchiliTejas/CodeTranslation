N = int(input())
str = list(input())
K = int(input()) - 1
str_list = list(str)
for i in range(N):
    if str[i] != str[K]:
        str[i] = '*'
str_changed = ''.join(str)
print(str_changed)
