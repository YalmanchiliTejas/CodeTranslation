N=int(input())
l=[int(i) for i in input().split()][:N]
arr=[-1]*N
arr[0]=l[0]
for i in range(1,N):
    arr[i]=arr[i-1]+l[i]
cnt=0
for i in range(N-1):
    cnt+=(l[i]*(arr[-1]-arr[i]))%1000000007
print(cnt%1000000007)