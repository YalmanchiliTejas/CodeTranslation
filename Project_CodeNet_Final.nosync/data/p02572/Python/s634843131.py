N = int(input())
suji = list(map(int, input().split()))

wa = sum(suji)
goukei = 0

for i in range(N):
    goukei += suji[i] * (wa - suji[i])
    wa -= suji[i]

print(goukei % (10 ** 9 + 7))