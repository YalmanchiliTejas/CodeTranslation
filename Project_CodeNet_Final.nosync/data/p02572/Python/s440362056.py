MOD = 10**9+7

n = int(input())
a = list(map(int, input().split()))

a1 = sum(a)
a2 = sum([x*x for x in a])

print(((a1**2-a2)//2)%MOD)