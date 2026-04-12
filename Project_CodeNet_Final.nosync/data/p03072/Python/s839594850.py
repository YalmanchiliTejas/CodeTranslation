N = int(input())
H = list(map(int, input().split()))

n = 0
x = 0
for h in H:
    if x <= h:
        x = x + 1
        n = n + 1
        x = h
print(n)
