N = int(input())
A = list(map(int,input().split()))
S = sum(A)
S2 = sum(map(lambda x:x**2,A))
 
print((S**2-S2)//2%(1000000000+7))
