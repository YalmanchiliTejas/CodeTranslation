n = int(input())
arr = list(map(int, input().split()))

step = 0
while max(*arr) >= n:
    arr = sorted(arr)
    cnt = arr[-1] // n
    arr[-1] -= cnt * n
    for i in range(n - 1):
        arr[i] += cnt
    step += cnt

print(step)