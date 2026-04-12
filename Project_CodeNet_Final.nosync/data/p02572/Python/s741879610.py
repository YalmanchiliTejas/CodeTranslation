n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
S = sum(a)
S2 = sum(map(lambda x:x*x, a))
print((S*S-S2)//2%mod)