n = int(input())
s = input()
k = int(input())

char = s[k-1]

ret_list = []

for i in range(len(s)):
    if s[i] == char:
        ret_list.append(s[i])
    else:
        ret_list.append('*')

print("".join(ret_list))

