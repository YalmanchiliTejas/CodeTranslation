N = int(input())
A = list(map(int, input().split()))
ssum = sum(A)
ans = 0
for a in A:
    ssum -= a
    ans += a * ssum
    ans %= 1000000007

print(ans)