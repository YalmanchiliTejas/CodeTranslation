n = int(input())
s = list(input())
k = int(input())

c = s[k-1]

for i in range(n):
    if s[i] != c:
        s[i] = '*'

print(''.join(s))