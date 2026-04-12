N, K = map(int, input().split())

ans = 0

for b in range(1, N+1):
    p = N // b
    r = N % b
    ans += p * max(0, b - K)  # 繰り返される部分
    ans += max(0, r - K + 1)  # 最後に付け加えられる部分

if K == 0:
    # 1~NのN回 b に関する演算を行なっているから -N
    ans -= N  # 各bに対して,本来許されない a=0 をカウントしてしまっているから帳尻合わせをする

print(ans)
