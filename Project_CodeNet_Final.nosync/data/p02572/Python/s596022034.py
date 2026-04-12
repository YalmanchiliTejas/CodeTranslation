try:
    n=int(input())
    m=10**9+7
    arr=[int(i) for i in input().split()]
    sm=sum(arr)%m
    ans=0
    for i in range(n-1):
        sm-=arr[i]
        x=arr[i]*sm
        ans+=x
        #print(x)
    print(ans%m)
except  EOFError as e:
    print(e)
