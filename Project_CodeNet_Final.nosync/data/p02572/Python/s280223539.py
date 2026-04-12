N = int(input())
As = list(map(int, input().split()))

total = 0
before = 0
for i in range(len(As) - 1):
    if i == 0:
        total = total + As[i] * sum(As[i+1:])
        before = sum(As[i+1:])
    else:
        total = total + ((before - As[i]) * As[i])
        before = before - As[i]

total = total % (10**9 + 7)

print(int(total))