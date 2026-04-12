N=int(input())
S=input()
s=[]
for i in S:
    s.append(i)
K=int(input())
letter=s[K-1]
ans=''
for i in s:
    if i==letter:
        ans+=i
    else:
        ans+='*'
print(ans)
