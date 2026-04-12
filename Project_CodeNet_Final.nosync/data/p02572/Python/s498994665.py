n = int(input())
la = list(map(int, input().split()))
MOD = 10**9+7
s1 = sum(la)
s2 = sum([x**2 for x in la])
ans = (s1*s1-s2)//2%MOD
print(ans)