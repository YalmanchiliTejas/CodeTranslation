n,x=map(int,input().split())

bp=[]
h=[]
for i in range(n+1):
    bp.append([2**(i+1)-2,2**(i+1)-1])
    h.append(2**(i+2)-3)


p=0
while x!=0:
    if n==0:
        p+=1
        x=0
    elif x<=h[n-1]+1:
        x=x-1
    elif x==h[n-1]+2:
        p+=1
        x=x-2
    elif x<=2*h[n-1]+2:
        p+=bp[n-1][1]+1
        x=x-h[n-1]-2
    else:
        p+=2*bp[n-1][1]+1
        x=0
    n=n-1

print(p)