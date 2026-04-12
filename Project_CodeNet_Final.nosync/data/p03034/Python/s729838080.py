n = int(input())
s = list(map(int, input().split()))

ans = 0

for d in range(1, n):
    temp = 0
    L = 0
    R = n-1
    if (n-1) % d == 0:
        while L < R:
            temp += s[L] + s[R]
            ans = max(ans, temp)
            L += d
            R -= d
    else:
        while L + d < n-1:
            temp += s[L] + s[R]
            ans = max(ans, temp)
            L += d
            R -= d

print(ans)