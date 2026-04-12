n = int(input())
s = list(input())
a = int(input())
inde = s[a-1]

ans = ""

for i in s:
    if(i != inde):
        ans += "*"
    else:
        ans += i
print(ans)