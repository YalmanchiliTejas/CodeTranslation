n = int(input())
Ai = list(map(int, input().split()))

sum_ans = sum(Ai)
ans = 0
mod = 1000000007

for i in range(n-1):
    sum_ans -= Ai[i]
    ans += sum_ans * Ai[i]
    ans %= mod

print(ans)