n = int(input())
s = input()
k = int(input())
str = []

for i in range(n):
    if(s[i] != s[k-1]):
        str.append("*")
    else:
        str.append(s[i])

print("".join(str))
