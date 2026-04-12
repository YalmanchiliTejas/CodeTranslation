
n = int(input())
item = [int(i) for i in input().split()]
mod = 10**9+7
t = (sum(item)**2 - sum([i**2 for i in item]))

print(int(t * pow(2, -1, mod)) % mod)
