s = input()
ans = "No"
pre = s[0]
for i in range(1,3):
    if(s[i] != pre):
        ans = "Yes"
        break
    pre = s[i]
print(ans)