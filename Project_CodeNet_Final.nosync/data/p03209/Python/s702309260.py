def depth(n):
    return 2**(n+2)-3

def totalp(n):
    return 2**(n+1)-1

def eat(n,x):
    if n == 0:
        return x
    elif x <= 1:
        return 0
    elif x >= depth(n)-1:
        return totalp(n)
    elif x == depth(n-1) + 2:
        return totalp(n-1) + 1
    elif x > depth(n-1)+2:
        return totalp(n-1) + 1 + eat(n-1,x-depth(n-1)-2)
    else:
        return eat(n-1,x-1)

(N,X) = map(int,input().split())
print(eat(N,X))