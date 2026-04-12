n=int(input())
lists=[]
for i in range(n):
    s=int(input())
    lists.append(s)

lis=sorted(lists)
if n%2==0:
    sig=sum(lis)
    left=sum(lis[:n//2])
    print(2*sig-4*left+lis[n//2-1]-lis[n//2])
if n%2!=0:
    sig=sum(lis)
    print(max(2*sig-4*sum(lis[:(n-1)//2])-lis[(n-1)//2]-lis[(n+1)//2], 2*sig-4*sum(lis[:(n+1)//2])+lis[(n-1)//2]+lis[(n-3)//2]))
    