#h,w=map(int,input().split())
import string
al=string.ascii_lowercase
n=int(input())
ss=[]
for i in range(n):
    s=input()
    t=[]
    for i in al:
        t.append(s.count(i))
    ss.append(t)

ans=[]
for i in range(26):
    mi=10**10
    for j in ss:
        mi=min(j[i],mi)
    ans+=[mi]

t=''
for i in range(26):
    t+=al[i]*ans[i]
print(t)
