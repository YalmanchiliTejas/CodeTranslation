n=int(input())
s=input()
k=int(input())
ans=[]
for i in range(n):
    if s[i]==s[k-1]:
        ans.append(s[i])
    else:
        ans.append('*')
print(''.join(ans))