n=int(input())
s=input()
k=int(input())
ch = s[k-1]
ans = ''
for i in range(n):
    if s[i] == ch:
        ans += ch
    else:
        ans += '*'
print(ans)