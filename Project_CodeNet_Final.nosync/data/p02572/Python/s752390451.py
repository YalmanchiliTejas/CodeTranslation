N = int(input())
A = list(map(int,input().split()))
s = [0]
for i in range(N):
    s.append(s[i] + A[i])
ans = 0
for i in range(N):
    ans += A[i] * (s[N] - s[i + 1])
print(ans % (10 ** 9 + 7))
