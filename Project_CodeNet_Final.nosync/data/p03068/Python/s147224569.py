n = int(input())
s = input()
k = int(input())
l = []
for i in range(n):
    if s[i] == s[k - 1]:
        l.append(s[i])
    else:
        l.append('*')
print(''.join(l))