N = int(input())
h = list(map(int, input().split()))
ans = 0
s = [h[N-1]]
for i in range(1, N):
    s.append(s[-1] + h[-i-1])
for i in range(N-1):
    ans += h[i] * s[-i-2]
ans = ans % (10 ** 9 + 7)
print(int(ans))