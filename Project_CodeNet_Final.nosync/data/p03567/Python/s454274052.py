s=input()

ans='No'
for i in range(len(s)-1):
    if s[i:i+2]=='AC':
        ans='Yes'
        break
print(ans)
