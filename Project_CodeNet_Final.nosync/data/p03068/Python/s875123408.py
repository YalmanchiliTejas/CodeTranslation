n = int(input())
s = list(input())
k = int(input())
ans = ''
for i in range(n):
    if s[i] != s[k-1]:
        s[i] = '*'
    else:
        continue
print(*s, sep='')