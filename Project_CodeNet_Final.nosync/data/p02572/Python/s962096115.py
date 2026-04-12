_ = input()
ans = b = 0
for a in map(int, input().split()):
    ans += a * b
    b += a
print(ans % (10**9 + 7))
