n = int(input())
arr = list(map(int, input().split()))

mod = 10 ** 9 + 7
sums = sum(arr)

answer = 0
for num in arr:
    sums -= num
    answer = (answer + (sums * num)) % mod

print(answer)