N = int(input())
i = list(map(int, input().split()))
MAX = i[0]
count = 0
for x in range(N):
    if i[x] >= MAX:
        MAX = i[x]
        count += 1
print(count)
