n = int(input())
s = list(input())
k = int(input())
d = s[k - 1]
for i in range(n):
    if s[i] != d:
        s[i] = '*'
print(''.join(s))
