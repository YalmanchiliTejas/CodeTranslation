n = int(input())
s = input()
k = int(input())
p = s[k-1]
x = ''
for i in s:
    if i != p:
        x += '*'
    else:
        x += i
print(x)