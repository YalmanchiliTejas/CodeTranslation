n = input()
s = input()
k = int(input())
ans = ''
target = s[k-1]
for i in s:
    if i == target:
        ans += i
    else:
        ans += '*'
print(ans)