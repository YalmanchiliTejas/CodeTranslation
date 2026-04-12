N = int(input())
As = [int(a) for a in input().split()]
hmax = 0
count = 0
for A in As:
    if hmax <= A:
        hmax = A
        count += 1
print(count)