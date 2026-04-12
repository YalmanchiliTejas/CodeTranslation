n=int(input())
h=list(map(int,input().split()))
x=1
for i in range(1,n):
    if h[i]>=max(h[:i]):
        x+=1
print(x)