n = int(input())
lst = list(map(int,input().split()))
mod = 10 ** 9 + 7

ans = 0
S = sum(lst)

for i in range(n-1):
    S = S - lst[i]
    tmp = lst[i] * S
    ans = (ans + tmp) % mod

print(ans)