N =int(input())
A = list(map(int,input().split()))
suma = sum(A)
Ans = 0
for a in A:
    suma -= a
    Ans += suma*a
    Ans = Ans % (10**9+7)
print(Ans)