n = int(input())
A = list(map(int, input().split()))

sum_value = sum(A)
m = 10**9 + 7

answer = 0
for a in A:
    sum_value -= a
    answer += ((a * sum_value) % m)

print(answer % m)
