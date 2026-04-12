N = int(input())
ans = 0
ans += N * 800
ans -= (N // 15) * 200
print(ans)