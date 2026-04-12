a=(int(input()))
b=list(map(int,input().split()))
c=0
d=b[0]
for i in range(1,a):
    c+=(d*b[i])
    d+=b[i]
print(c%1000000007)

