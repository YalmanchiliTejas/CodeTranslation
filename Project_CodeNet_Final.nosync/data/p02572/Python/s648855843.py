N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
total = sum(A)
ans = (sum(list(map(lambda a: (total-a)*a, A))) // 2) % mod
print(ans)