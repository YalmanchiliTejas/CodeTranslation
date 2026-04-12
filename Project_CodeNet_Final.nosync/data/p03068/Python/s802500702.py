n=int(input())
s=input()
k=int(input())
s0 = s[k-1]
ans = ''
i = 0
while i < len(s):
    if s[i] != s0:
        ans += '*'
    else:
        ans += s[i]
    i += 1
print(ans)