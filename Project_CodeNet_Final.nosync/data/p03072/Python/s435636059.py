n = int(input())
h = list(map(int, input().split()))
def gov(n, h):
    ans = 1
    for i in range(1, n):
        cnt = 0
        for j in range(i):
            if h[j] == max(h[i], h[j]) and h[i] != h[j]:
                break
            cnt += 1
        if cnt == i:
            ans += 1
    return ans
print(gov(n, h))