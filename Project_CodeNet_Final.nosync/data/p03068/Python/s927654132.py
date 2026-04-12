n = int(input())
s = input()
k = int(input())
t = [''] * n

for i in range(n):
    if s[i] == s[k - 1]:
        t[i] = s[i]
    else:
        t[i] = '*'

print(''.join(t))
