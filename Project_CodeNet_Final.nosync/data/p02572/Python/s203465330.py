N = int(input())
L = list(map(int,input().split()))

ans = 0

S = sum(L)
for i in range(len(L)-1):
    ans += L[i] * (S- L[i])
    S -= L[i]
    
print(ans % (10**9 + 7))