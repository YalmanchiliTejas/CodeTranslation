#Tenka1 Programmer Beginner Contest 2019 b
n=int(input())
s=input()
k=int(input())-1
x=s[k]
ans=""
for c in s:
    if c==x:
        ans+=c
    else:
        ans+="*"
print(ans)