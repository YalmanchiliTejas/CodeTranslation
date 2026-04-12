n=int(input())
p=list(map(str,input().split()))
m=p[0]
for i in range(1,n):
    if m+p[i]=="TF":
        m="F"
    else:
        m="T"
print(m)
