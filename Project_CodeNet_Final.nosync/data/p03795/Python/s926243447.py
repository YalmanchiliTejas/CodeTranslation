n = int(input())

payback = int((n//15) * 200)
charges = 800 * n

ans = charges - payback
print(ans)