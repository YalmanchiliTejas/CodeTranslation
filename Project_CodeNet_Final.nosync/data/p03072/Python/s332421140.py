N = int(input())
H = list(map(int, input().split()))
ans = 1
if N > 1:
    t = H[0]
    for i in range(1, N):
        if H[i] >= t:
            t = H[i]
            ans += 1
print(ans)
