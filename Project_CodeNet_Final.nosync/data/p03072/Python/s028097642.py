N=int(input())
h=list(map(int,input().split()))
cnt=1
i=1
while i<N:
    if h[i]>=max(h[:i]):
        cnt+=1
    i+=1
print(cnt)
    