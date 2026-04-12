import sys
input = sys.stdin.readline
n = int(input()) # 入力が1つ
# map(int, input().split()) # 入力が複数
# [int(i) for i in input().split()] # 配列で数字
ans = 800 * n - 200 * (n // 15)
print(ans)