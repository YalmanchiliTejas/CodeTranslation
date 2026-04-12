# coding: utf-8
# Your code here!

n=int(input())
s=input()
k=int(input())
'''
#a,b=map(int,input().split())
a=[int(i) in range(n)]
a=[0]*n
for i in range(n):
    a.append(int(i))
'''

t=s[k-1]
ans=''
for i in range(n):
    if s[i]==t:
        ans+=t
    else:
        ans+='*'
print(ans)