N = int(input())
Ai = list(map(int, input().split()))

gokei = 0
now_sum = sum(Ai)

for i in Ai:
    now_sum -= i
    gokei += i * (now_sum)

print(gokei % 1000000007)