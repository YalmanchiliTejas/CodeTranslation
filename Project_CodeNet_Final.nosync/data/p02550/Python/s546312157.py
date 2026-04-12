N, X, M = map(int, input().split())

L = [-1] * M

a = X
i = 0
while True:
    if L[a] != -1:
        B = L[a]
        C = i - L[a]
        break
    L[a] = i
    a = a * a % M
    i += 1


ans = 0
if N <= B + C:
    a = X
    for i in range(N):
        ans += a
        a = a * a % M
else:
    a = X
    for i in range(B):
        ans += a
        a = a * a % M
    temp = 0
    for i in range(B, B+C):
        temp += a
        a = a * a % M
    ans += (N-B) // C * temp
    for i in range((N-B)%C):
        ans += a
        a = a * a % M
print(ans)
    