# 2019/09/12

n=int(input())
s=list(input())
k=int(input())

K=s[k-1]
for i in range(n):
    if s[i]==K:continue
    s[i]='*'
print(*s,sep='')