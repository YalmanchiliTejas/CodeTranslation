n=int(input())
h=list(map(int, input().split()))
res =1
x=h[0]
for i in range(1,n):
    if x<=h[i]:
        res +=1
        x=h[i]
print(res)