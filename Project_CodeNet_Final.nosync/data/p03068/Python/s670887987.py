n = int(input())
s = list(input())
k = int(input())

target = s[k-1]

ans = ""

for i in range(len(s)):
    if(s[i]==target):
        ans += target
    else:
        ans += "*"

print(ans)