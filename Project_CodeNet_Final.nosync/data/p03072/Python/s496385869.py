# B - Great Ocean View
# https://atcoder.jp/contests/abc124/tasks/abc124_b


n = int(input())
points = list(map(int, input().split()))
ans = 1
need_height = points[0]


for i in range(1, n):
    current = points[i]
    if need_height <= current:
        ans += 1
        need_height = current


print(ans)