n = int(input())
a = list(map(int, input().split()))
S = [0]*n
for i in range(0, n):
    if i > 0:
        S[i] = S[i-1] + a[i]
    else:
        S[i] = a[i]
ans = int(0)
m = int(1000000007)
for i in range(0, n):
    ans = (ans + (a[i] * (S[n-1]-S[i]))) % m
print(ans)