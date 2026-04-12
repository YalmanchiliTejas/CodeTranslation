n = int(input())
s = input()
k = int(input())

let = s[k-1]
new = ''
for i in s:
    if i == let:
        new += i
    else:
        new+= "*"

print(new)