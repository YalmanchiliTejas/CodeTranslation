n = int(input())
s = input()
k = int(input())

char = s[k-1]
ans=''
for i in s:
    if i!=char:
        ans+='*'
    else:
        ans+=char
print(ans)