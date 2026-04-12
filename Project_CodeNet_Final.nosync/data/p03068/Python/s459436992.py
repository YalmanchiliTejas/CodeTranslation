n = int(input())
s = input()
k = int(input())
t = s[k-1]
l = []

for i in range(n):
    if s[i] == t:
        l.append(t)
    else:
        l.append('*')

print(''.join(l))