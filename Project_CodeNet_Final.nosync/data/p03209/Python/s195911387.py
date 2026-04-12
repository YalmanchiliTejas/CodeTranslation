n, x =map(int,input().split())
def burger(n, x):
    if n == 0:
        if x == 0:
            return 0
        elif x == 1:
            return 1
    else:
        if x == 1:
            return 0
        elif x == 2**(n+2)-3:
            return 2**(n+1)-1
        elif x == 2**(n+1) -1 :
            return 2**n
        elif x > 2**(n+1) - 1: #(2**(n+1)-1)/2 + 1:
            return 2**n + burger(n-1, x - (2**(n+1) - 1))
        else:
            return burger(n-1, x-1)
          
print(burger(n, x))