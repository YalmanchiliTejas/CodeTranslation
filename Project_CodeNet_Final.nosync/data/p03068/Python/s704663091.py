n = int(input())
s = input()
k = int(input())
t = s[k-1]
ans = ""
for c in s:
    if c==t:
        ans += c
    else:
        ans += '*'
else:
    print(ans)