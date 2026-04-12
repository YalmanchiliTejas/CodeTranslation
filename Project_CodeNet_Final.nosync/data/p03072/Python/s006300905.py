n=int(input())
h=list(map(int,input().split()))
a=0
maxh=0
for i in range(n):
    if maxh<=h[i]:
        a+=1
        maxh=h[i]
print(a)
