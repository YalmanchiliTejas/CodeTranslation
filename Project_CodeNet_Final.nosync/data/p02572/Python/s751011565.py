n = int(input())
a = [int(i) for i in input().split()]
b = [i* i for i in a]
print((sum(a)**2 - sum(b))//2 % (10**9+7))