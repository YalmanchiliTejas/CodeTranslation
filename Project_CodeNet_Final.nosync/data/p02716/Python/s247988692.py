n = int(input())
a = [int(x) for x in input().split()]

# dp(直前の値を取っている)(最大個数取っている)
dp00 = 0
dp01 = -10**15
dp10 = -10**15
dp11 = a[0]

for i in range(1, n):
    if i % 2 != 0:
        dp01 = dp11
        dp11 = dp00 + a[i]
        dp00 = max(dp00, dp10)
        if i == 3:
            dp10 = a[i]
    else:
        dp10 = dp00 + a[i]
        dp00 = max(dp01, dp11)
        dp11 = dp01 + a[i]

if n % 2 == 0:
    print(max(dp01, dp11))
else:
    print(max(dp00, dp10))
