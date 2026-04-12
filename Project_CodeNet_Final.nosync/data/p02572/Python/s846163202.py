n = int(input())

An = [int(i) for i in input().split()]
S = sum(An)
Sn = S**2
Sn2 = 0
for a in An:
    Sn2 += a**2

ans = ((Sn - Sn2)//2)%(10**9+7)
print(ans)
