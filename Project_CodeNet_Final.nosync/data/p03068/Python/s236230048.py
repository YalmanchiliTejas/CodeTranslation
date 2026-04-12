n = int(input())
s = input()
k = int(input())

a = s[k-1]

s_list = list(s)

for i in range(n):
    if s_list[i] != a:
        s_list[i] = "*"

s1 = "".join(s_list)

print(s1)
