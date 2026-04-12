N = int(input())
A = [int(i) for i in input().split()]
S = []
e = 0
for i in A:
    e += i
    S.append(e)
    
ans = 0
for i in range(N-1):
    ans += A[i]%(10**9+7)*((S[N-1] - S[i])%(10**9+7))
    
print(ans%(10**9+7))