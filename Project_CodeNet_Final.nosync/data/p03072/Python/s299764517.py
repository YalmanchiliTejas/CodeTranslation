n=int(input())
h=list(map(int,input().split()))
an=1
ma=h[0]
 
for i in range(1,n):
    if ma <= h[i]:
        ma=h[i]
        an+=1
    
print(an)