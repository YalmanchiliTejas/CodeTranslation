n = int(input())
l = list(map(int, input().split()))
cnt = 1
for i in range(1, n):
    if l[i] >= max(l[:i]):
        cnt += 1
print(cnt)