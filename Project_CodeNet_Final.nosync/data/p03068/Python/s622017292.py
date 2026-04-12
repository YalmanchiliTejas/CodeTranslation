n = int(input())
s = input()
k = int(input())
nokosu = s[k-1]
ans = ""
for i in range(n):
    if s[i:i+1] != nokosu:
        ans += "*"
    else:
        ans += nokosu
print(ans)