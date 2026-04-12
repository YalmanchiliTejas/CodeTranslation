n = int(input())
s = input()
k = int(input())
ans = ''
moji = s[k - 1]
for i in range(n):
    if s[i] == moji:
        ans += moji
    else:
        ans +='*'
print(ans)