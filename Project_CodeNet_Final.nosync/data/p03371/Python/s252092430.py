a, b, c, x, y = map(int, input().split())
ans = []
for i in range(10**5 + 1):
    ans.append(i * (2*c) + a * max(0, x-i) + b * max(0, y-i))
print(min(ans))