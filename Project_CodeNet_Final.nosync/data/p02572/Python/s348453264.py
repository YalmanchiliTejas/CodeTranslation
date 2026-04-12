N = int(input())
As = list(map(lambda x: int(x), input().split(" ")))

result = 0
MOD = 10**9+7

S = sum(As)

for i in range(len(As)-1):
    S -= As[i]
    tmp = As[i] * S
    result += tmp
    result %= MOD

print(result)

