# B - Great Ocean View
# https://atcoder.jp/contests/abc124/tasks/abc124_b
n = int(input())
h = list(map(int, input().split()))
c = 1
H = h[0]
for i in h[1:]:
    if i >= H:
        c += 1
    if H < i:
        H = i
print(c)
