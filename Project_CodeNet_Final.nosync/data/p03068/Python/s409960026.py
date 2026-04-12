n = int(input())
s = list(input())
k = int(input())
change_c = s[k-1]
for i in range(n):
    if s[i] != change_c:
        s[i] = '*'

ans = ''.join(s)
print(ans)