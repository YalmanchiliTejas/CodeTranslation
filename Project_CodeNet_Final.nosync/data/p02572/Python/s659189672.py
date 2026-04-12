N = int(input())
A = list(map(int,input().split()))
B = sum([a**2 for a in A])
print(((sum(A)**2-B)//2)%(10**9+7))