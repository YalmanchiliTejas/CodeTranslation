N = int(input())
p = 10**9 + 7
A = [int(i) for i in input().split()]
S = sum(A)%p
ans = S**2 % p
B = [(i**2%p) for i in A]
ans -= sum(B)%p
if ans < 0:
    ans += p
if ans % 2 == 0:
    print(ans//2)
else:
    print((ans+p)//2)