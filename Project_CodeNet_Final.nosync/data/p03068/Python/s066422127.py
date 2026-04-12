n = int(input())
s = str(input())
k = int(input())

s =list(s)

for i in range(n):
    if s[i] != s[k-1]:
        s[i] = '*'

print(''.join(s))