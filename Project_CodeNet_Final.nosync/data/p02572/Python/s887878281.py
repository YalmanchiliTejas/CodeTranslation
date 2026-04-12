def sumproductsofpairs(lst):
    total = 0
    psum = 0
    for x in lst:
        total += psum * x
        psum += x
    return total%(1000000007) 
b=int(input())
A=list(map(int,input().split()))
print(sumproductsofpairs(A))