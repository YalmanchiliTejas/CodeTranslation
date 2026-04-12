n=int(input())

x=list(input())
l=len(x)

for k in range(n-1):
    a=list(input())
    m=len(a)
    for i in range(l-1,-1,-1):
        for j in range(m-1,-1,-1):
            if x[i]==a[j]:
                del a[j]
                m-=1
                break
        else:
            del x[i]
            l-=1

x.sort()
   
print(''.join(x))
