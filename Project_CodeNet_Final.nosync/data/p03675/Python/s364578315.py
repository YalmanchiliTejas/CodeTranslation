n=int(input())
a=list(map(int,input().split()))
b=[]

if n%2==0:

    for i in range(n):

        if n-i*2-1 > 0:
            b.append(a[n-i*2-1])
        else:
            k=abs(n-i*2)
            b.append(a[k])

else:
    
    for i in range(n):

        if n-i*2-1 >= 0:
            b.append(a[n-i*2-1])
        else:
            k=abs(n-i*2-1)
            b.append(a[k-1])

print(*b)



