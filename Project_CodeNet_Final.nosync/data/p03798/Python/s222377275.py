n,s=int(input()),input()
s+=s[:2]
# 羊:0 狼:1
for i in range(2):
    for j in range(2):
        a=[0]*(n+2)
        a[0]=i
        a[1]=j
        for k in range(1,n+1):
            if a[k]==0:
                if s[k]=="o":
                    a[k+1]=a[k-1]
                else:
                    a[k+1]=not a[k-1]
            else:
                if s[k]=="o":
                    a[k+1]=not a[k-1]
                else:
                    a[k+1]=a[k-1]
        if a[0]==a[n] and a[1]==a[n+1]:
            print(*["W" if k else "S" for k in a[:n]],sep="")
            exit()
print(-1)