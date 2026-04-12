# coding: utf-8
# Your code here!
b=input()
s=input()
n=int(input())-1
a=s[n]
ans=""
#print(a)
for i in range(len(s)):
    m=s[i]
    if(s[i]!=a):
        m="*"
    ans+=m
print(ans)