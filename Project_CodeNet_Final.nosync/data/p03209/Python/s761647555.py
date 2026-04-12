N,X=map(int,input().split())
dp={}
def f(n,x):
    if (n,x) in dp:
        return dp[(n,x)]
    elif (n,x)==(0,1):
        return 1
    else:
        if x==1:
            answer=0
            return answer
        elif 2<=x<=2**(n+1)-2:
            answer=f(n-1,x-1)
            return answer
        elif x==2**(n+1)-1:
            answer=f(n-1,2**(n+1)-3)+1
            return answer
        elif 2**(n+1)<=x<=2**(n+2)-4:
            answer=f(n-1,2**(n+1)-3)+f(n-1,x-2**(n+1)+1)+1
            return answer
        else:
            answer=2*f(n-1,2**(n+1)-3)+1
            return answer
print(f(N,X))
            
            
