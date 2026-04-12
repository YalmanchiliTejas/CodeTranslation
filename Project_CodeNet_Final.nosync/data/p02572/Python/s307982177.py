N = int(input())
a = list(map(int, input().split()))
a.reverse()
mod = 10**9 +7
ans = 0
S=[0]
for i in range(0,N):
    S.append(S[i]+a[i])
ans = 0
for j in range(len(a)):
    ans +=(a[j]*S[j])
print(ans%mod)