n = int(input())
s = input()
k = int(input())
for N in range(n):
    if s[N] != s[k -1]:
        s = s.replace(s[N],'*')
print(s)