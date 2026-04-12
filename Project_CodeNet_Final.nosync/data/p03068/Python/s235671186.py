n = int(input())
s = input()
k = int(input())
for i in set(s):
    if i == s[k-1]:
        continue
    else:
        s = s.replace(i, '*')
print(s)