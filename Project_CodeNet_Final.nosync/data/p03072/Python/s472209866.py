n = int(input())

xs = [int(x) for x in input().split()]

mx = xs[0]
count = 0
for x in xs:
    if x >= mx:
        count += 1
        mx = x

print(count)
