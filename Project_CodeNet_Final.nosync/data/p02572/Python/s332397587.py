n=int(input())
xs=[int(x) for x in input().split()]

F=10**9+7
print((sum(xs)*sum(xs) - sum([x**2 for x in xs]))//2%F)