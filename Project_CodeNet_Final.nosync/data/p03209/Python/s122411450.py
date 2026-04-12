n,x=map(int,input().split())
def eat(n,x):
    if x==0:
        return 0
    if n==0 and x==1:
        return 1
    
    if n>=1:
        if x<=2**(n+1)-2:
            return eat(n-1,x-1)
        elif x==2**(n+1)-1:
            return eat(n-1,2**(n+1)-3)+1
        elif 2**(n+2)-3>x>=2**(n+1):
            return eat(n-1,2**(n+1)-3)+1+eat(n-1,x+1-2**(n+1))
        elif x==2**(n+2)-3:
            return 2*eat(n-1,2**(n+1)-3)+1
print(eat(n,x))