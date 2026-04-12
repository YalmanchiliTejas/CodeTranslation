N, nums = int(input()), list(map(int, input().split()))

score = [[(-1 if N % 2 == 0 else 1)*x for x in nums]]
for i in range(1, N):
    temp = []
    for j in range(N - i):
        func, sign = (min, -1) if i % 2 == N % 2 else (max, 1)
        temp.append(func(sign*nums[j] + score[-1][j + 1], sign*nums[j + i] + score[-1][j]))
    score.append(temp)

print(score[-1][-1])
