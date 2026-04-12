n = int(input())
h = [int(i) for i in input().split()]
cnt = 0
for i in range(n):
    if max(h[:i + 1]) <= h[i]:
        cnt += 1
print(cnt)