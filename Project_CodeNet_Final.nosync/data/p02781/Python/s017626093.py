N = int(input())
K = int(input())
S = str(N)
n = len(S)
def c(x,y):
    X = 1
    Y = 1
    for i in range(y):
        X *= (x-i)
        Y *= (y-i)
    return X//Y
k = K
ans = 0
for i in range(n):
    if k < 0:
        break
    x = int(S[i])
    y = n - 1 - i
    if i == 0:
        k -= 1
        ans += (x-1)*(9**k)*(c(y,k))
        continue
    if x == 0:
        continue
    k -= 1
    if k >= 0:
        ans += (x-1)*(9**k)*(c(y,k))
    ans += (9**(k+1))*c(y,(k+1))
if i == n-1:
    if k == 0:
        ans += 1
for i in range(1,n):
    if i < K:
        continue
    ans += (9**K)*c(i-1,K-1)
print(ans)