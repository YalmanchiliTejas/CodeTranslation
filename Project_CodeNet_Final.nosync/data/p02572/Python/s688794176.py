n=int(input())
A=[int(x) for x in input().split()]

A2=[int(x)**2 for x in A]
print(((sum(A)**2-sum(A2))//2)%(10**9+7))
