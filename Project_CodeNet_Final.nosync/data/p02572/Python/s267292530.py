n = int(input())
li = list(map(int,input().split()))
mod = 10**9+7

S = sum(li)
li2 = [x**2 for x in li]
S2 = sum(li2)

print((S**2-S2)//2%mod)