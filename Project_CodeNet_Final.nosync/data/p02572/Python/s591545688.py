from functools import reduce
mod = 10**9 + 7

n = int(input())
arr = list(map(int, input().split()))
to_mutiply = [0]*n

for i in range(n-2, -1, -1):
    to_mutiply[i] = to_mutiply[i+1] + arr[i+1]

data = list(map(lambda i: (to_mutiply[i]*arr[i]) % mod, range(n-1)))
print(reduce(lambda x, y: (x+y) % mod, data))
