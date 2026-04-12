n=int(input())
a=list(map(int,input().split()))
m=0
c=0
for x in a:
    if m<=x:c+=1
    m=max(m,x)
print(c)