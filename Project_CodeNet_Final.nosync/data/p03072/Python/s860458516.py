def solve(N, H):
    cnt = 0
    for i in range(N):
        if i == 0:
            cnt += 1
            continue
        max_height = max(H[:i])
        if max_height <= H[i]:
            cnt += 1
    return cnt


N = int(input())
H = list(map(int, input().split()))

print(solve(N, H))