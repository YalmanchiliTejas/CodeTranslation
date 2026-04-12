# 入力受け取り
N = int(input())
H = [int(i) for i in input().split(" ")]

num_int = 1 # 海を眺められる旅館の数
for i in range(1, N):
    j = 0
    while j < i and H[j] <= H[i]:
        j += 1
    if j == i:
        num_int += 1

print(num_int)