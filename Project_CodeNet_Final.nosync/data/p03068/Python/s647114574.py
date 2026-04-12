n = int(input())
s = input()
k = int(input())-1

res = ""
for i in s:
    if i!=s[k]:
        res += "*" 
    else:
        res += s[k]
else:
    print(res)
