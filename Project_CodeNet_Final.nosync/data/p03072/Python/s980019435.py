n = int(input())
heights = [int(i) for i in input().split()]

def check(num):
    for i in range(num):
        if heights[i] > heights[num]:
            return 0

    return 1

ans = 0

for i in range(n):
    if check(i) == 1:
        ans = ans + 1

print(ans)