n = input()
s = input()
k = int(input())

r = s[k - 1]
ans = ''
for i, v in enumerate(s):
    if v != r:
        ans += '*'
    else:
        ans += v

print(ans)