X_all, Y_hito, Z_interval = map(int, input().split())

syou = X_all // (Y_hito + Z_interval)

if (syou * (Y_hito + Z_interval) + Z_interval <= X_all):
    ans = syou
else:
    ans = syou - 1

print(ans)