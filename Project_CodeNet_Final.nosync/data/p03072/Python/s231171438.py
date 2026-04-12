n = int(input()) # 入力が1つ
# map(int, input().split()) # 入力が複数
m = [int(i) for i in input().split()] # 配列で数字

ans = 1
MAX = m[0]
for i in range(1, n):
    if m[i] >= MAX:
        ans += 1
    MAX = max(MAX, m[i])
print(ans)