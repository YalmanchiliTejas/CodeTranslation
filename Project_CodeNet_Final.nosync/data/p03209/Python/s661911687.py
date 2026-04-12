
N,X = map(int,input().split())


eat = 0

def eat(n,x):
    if x == 0:
        return 0
    elif n== 0:
        return 1
    elif 2**(n+2)-3 <= x:
        return 2**(n+1)-1
    elif 2**(n+2)-3 > x and 2**(n+1)-1 <=x :
        return 2**n-1 + 1 + eat(n-1,x-(2**(n+1)-1))
    else:
        return eat(n-1,x-1)

print(eat(N,X))   
