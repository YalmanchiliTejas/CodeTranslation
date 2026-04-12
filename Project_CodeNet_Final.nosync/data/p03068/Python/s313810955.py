n = int(input())
s =input()
k =int(input())
t = s[k - 1]
p = ""
for i in range(n):
    if s[i] != t:
        p += "*"
    else:
        p += s[i]
print(p)