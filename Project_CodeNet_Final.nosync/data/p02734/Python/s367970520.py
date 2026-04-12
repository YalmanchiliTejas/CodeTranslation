mod = 998244353

# N,S,A <= 3000

N,S = map(int,input().split())
A = list(map(int,input().split()))

DP = [0]*S
DP[0] = 1
ans = 0

for i in range(N):
    #print(DP)
    #print(ans)
    a = A[i]
    for j in range(S):
        k = S-1-j
        if k+a <S:
            if k==0:
                DP[k+a] += i+1
            else:
                DP[k+a] += DP[k]
        elif k+a ==S:
            if k==0:
                ans += (i+1)*(N-i)
                ans %= mod
            else:
                ans += DP[k]*(N-i)
                ans %= mod

#print(DP)
print(ans)