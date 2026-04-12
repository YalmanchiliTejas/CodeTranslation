n = int(input())
s = input()
k = int(input())
ans = ''
sk = s[k-1]
for i in range(n):
    if s[i] == sk:
        ans += sk
    else:
        ans += '*'
print(ans)