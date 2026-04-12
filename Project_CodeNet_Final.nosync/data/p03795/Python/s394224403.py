N = int(input())

ans = 0
ans += 800 * N
ans -= 200 * (N // 15)

print(ans)