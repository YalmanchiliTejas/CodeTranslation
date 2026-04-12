n=int(input())
h=list(map(int,input().split()))
c=0
m=h[0]
for _ in range(n):
    if m<=h[_]:
        c +=1
        m=h[_]
print(c)