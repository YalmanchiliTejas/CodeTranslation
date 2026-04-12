n = input()
s = input()
k = int(input())
ans=""

rep = s[k-1]
for ss in s:
    if ss != rep:
        ans += "*"
    else:
        ans += rep
print(ans)