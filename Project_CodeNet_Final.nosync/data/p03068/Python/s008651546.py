n = int(input())
s = list(str(input()))
k = int(input())
k -= 1
for i in range(n):
    if s[i] != s[k]:
        s[i] = '*'
print(''.join(s))
