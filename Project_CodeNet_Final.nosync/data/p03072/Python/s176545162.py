n = int(input())
h = list(map(int, input().split()))
highest = h[0]
answer = 1
for i in range(1, n):
    if h[i] >= highest:
        answer += 1
        highest = h[i]

print(answer)
