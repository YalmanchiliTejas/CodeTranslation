n = int(input())
s = input()
k = int(input())
t = s[k - 1]
l = []
for i in s:
    if t != i:
        l.append('*')
    else:
        l.append(t)
print(''.join(l))