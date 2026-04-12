n = input()
s = input()
k = int(input())
s_list = list(s)
for i in range(len(s_list)):
    if s_list[i] != s_list[k-1]:
        s_list[i] = "*"
s_changed = "".join(s_list)
print(s_changed)