n=int(input())
h=list(map(int,input().split()))
o=h[0]
u=1
for i in range(1,n):
    if h[i-1]<=h[i] and o<=h[i]:
        u+=1
        o=h[i]
print(u)