while True:
    n=input()
    if n==0:break
    print sum(sorted([input() for i in range(n)])[1:-1])/(n-2)