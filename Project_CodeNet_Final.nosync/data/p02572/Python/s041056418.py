def fastSumPair(A):
    L = len(A)
    M = 1000000007
    
    # (a + b + c)**2 = a**2 + b**2 + c**2 + 2*(a*b + b*c + c*a)
    # derive from this equation
    
    # first array
    A_1_sum = 0
    for i in range(0, L):
        A_1_sum = (A_1_sum + A[i]) 
    
    A_1_sum = (A_1_sum ** 2) 
        
    # second array
    A_2_sum = 0
    for i in range(0, L):
        A_2_sum = (A_2_sum + A[i] ** 2) 
                  
    return int((A_1_sum - A_2_sum) // 2) % M        

N = int(input())
A = list(map(int, input().rstrip().split()))
print(fastSumPair(A))