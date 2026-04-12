# print('input >>')
N = input()
As = list(map(int,(input().split())))
MOD = 10**9 + 7

As_sum = [As[0]]

for i in range(1, len(As)):
    As_sum.append((As_sum[-1]+As[i]) % MOD)

ans = 0
for i in range(len(As)-1, 0, -1):
    ans += As[i] * As_sum[i-1]
    ans %= MOD

# print('-----output-----')
print(ans % MOD)