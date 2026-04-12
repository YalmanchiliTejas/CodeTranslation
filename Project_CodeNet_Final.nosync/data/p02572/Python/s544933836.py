M=10**9+7
n=int(input())
l=[*map(int,input().split())]
print((sum(i for i in l)**2-sum(i**2 for i in l))//2%M)