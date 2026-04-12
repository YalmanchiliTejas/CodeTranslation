n = int(input())
# = map(int, input().split())
h = list(map(int, input().split()))
# = [int(input()) for _ in range()]
cnt = 1
for i in range(1, n):
    if h[i] >= max(h[:i]):
        cnt += 1
print(cnt)
