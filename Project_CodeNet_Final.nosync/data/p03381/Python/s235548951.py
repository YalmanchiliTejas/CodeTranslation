n=int(input())
x=list(map(int,input().split()))
y=sorted(x)
midl=y[n//2-1]
midr=y[n//2]
for i in range(n):
    print(midl if x[i]>midl else midr)