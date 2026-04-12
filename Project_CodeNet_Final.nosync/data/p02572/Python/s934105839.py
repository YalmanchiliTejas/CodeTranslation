D = 10 ** 9 + 7
N = int(input())
L= list(map(int, input().split()))

ans = L[0] * L[1] % D
sub = L[0] + L[1]
for n in range(2,N):
    ans += L[n] * sub
    sub += L[n]
    
print(ans % D)