n = int(input())

A = list(map(int, input().split()))

c = 0
m = 0
for i in A:
    if i>=m:
        c += 1
        m = i
print(c)