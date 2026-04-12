N = int(input())
As = list(map(int, input().split()))
mod = (10 ** 9) + 7
mod2 = 2 * mod

sum1 = sum(As) % mod2
squared1 = (sum1 ** 2) % mod2

squared2 = 0

for i in range(N):
    squared2 += (As[i] ** 2) % mod2

print(int((squared1 - squared2) / 2) % mod)