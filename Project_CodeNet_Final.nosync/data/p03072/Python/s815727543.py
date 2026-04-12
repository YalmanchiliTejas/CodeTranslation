n = int(input())
h = list(map(int, input().split()))
sum = 0
m = 0
for i in h:
    if m <= i:
        sum += 1
        m = i
print(sum)