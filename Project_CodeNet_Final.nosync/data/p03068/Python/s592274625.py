n = int(input())
s = input()
k = int(input())
list_s = list(s)

a = s[k - 1]

for i in range(n):
    if(s[i] != a):
        list_s[i] = "*"
s_dash = "".join(list_s)
print(s_dash)