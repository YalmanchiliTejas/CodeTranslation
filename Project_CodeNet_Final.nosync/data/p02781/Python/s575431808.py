n=int(input())
k=int(input())
s=len(list(str(n)))
if k==1:
    ans=(s-1)*9
    for i in range(9):
        if n>=(10**(s-1))*(i+1):
            ans+=1
elif k==2:
    ans=9*9*(s-1)*(s-2)//2
    for i in range(9):
        for j in range(s-1):
            for p in range(9):
                if n>=(10**(s-1))*(i+1)+(10**j)*(p+1):
                    ans+=1
else:
    ans=9*81*(s-1)*(s-2)*(s-3)//6
    f=int(list(str(n))[0])
    ans+=(f-1)*81*(s-1)*(s-2)//2
    for p in range(s-1):
        for q in range(s-1):
            if p<q:
                for t in range(1,10):
                    for u in range(1,10):
                        if n>=(10**(s-1))*f+(10**p)*t+(10**q)*u:
                            ans+=1
print(ans)
