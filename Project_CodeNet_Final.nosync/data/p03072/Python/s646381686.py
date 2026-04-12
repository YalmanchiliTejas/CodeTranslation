n=int(input())
h=list(map(int,input().split()))
a=0
b=0
for i in range(n):
    if h[i]>=a:
        b+=1
    
        a=h[i]
print(b)