N = int(input())
H = list(map(int, input().split()))

ans = 1
for i, h in enumerate(H[1:]):
    if h >= max(H[:i+1]):
        ans += 1
print(ans)
