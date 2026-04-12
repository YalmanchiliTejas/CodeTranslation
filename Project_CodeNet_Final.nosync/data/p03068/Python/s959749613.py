n = int(input())
s = input()
k = int(input())
for i in s:
    if i != s[k - 1]:
        s = s.replace(i, '*')
print(s)