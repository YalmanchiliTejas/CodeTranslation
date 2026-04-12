n = int(input())
s = input()
k = int(input())

a = s[k-1]
li = []
s2 = ''

for i in range(n):
    if s[i] != a:
        li.append(i)

for i in range(n):
    if i in li:
        s2 = s2 + '*'
    else:
        s2 = s2 + s[i]

print(s2)
