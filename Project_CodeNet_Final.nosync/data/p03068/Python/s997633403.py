n = int(input())
s = input()
k = int(input())

moji = s[k-1]
ans = ""
for i in range(len(s)):
    if s[i] != moji:
        ans += str("*")
    else:
        ans += str(s[i])
    
print(ans)