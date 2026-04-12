a, b, c, x, y = map(int, input().split())
tot = [0] * 100001
for i in range(100001):
    tot[i] = i*2*c + max(0, x-i)*a + max(0, y-i)*b
print(min(tot))