while True:    
    n=int(input())
    if n == 0:
        break 
    else:
        A=[]
        for i in range(n):
            A.append(int(input()))
        print((sum(A)-max(A)-min(A))//(n-2))
