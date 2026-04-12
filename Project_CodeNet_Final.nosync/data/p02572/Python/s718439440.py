
md=10**9+7
t=1
# t=int(input())

for some_num in range(0,t):
    n=int(input())
    vals=[int(i) for i in input().split(" ")]

    s=0
    for i in range(0,n):
        s=(s+vals[i])%md

    csum=0

    for i in range(0,n-1):
        s-=vals[i]

        csum= (csum+vals[i]*s)%md

    print(csum)