N = int(input())
A = list(map(int,input().split()))

S1 = sum(A)
S2 = sum(map(lambda x:x*x, A))
         
print((S1 * S1 - S2) // 2 % 1000000007)