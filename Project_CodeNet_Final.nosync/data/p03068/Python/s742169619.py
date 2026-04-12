n = int(input())
s = input()
k = int(input())
string = s[k-1]
res = ""
for i in range(n):
    if s[i] != string:
        res += "*"
    else:
        res += string
print(res)