n = int(input())
l = [51] * 26
z = list('abcdefghijklmnopqrstuvwxyz')
for i in range(n):
    s = input()
    for j in range(26):
        l[j] = min(l[j],s.count(z[j]))

t = []
for i in range(26):
    if l[i] != 51:
        t.append((z[i]) * l[i])

print(''.join(t))