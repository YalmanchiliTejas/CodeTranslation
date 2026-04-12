N = int(input())
x = 0
y = 0
if N >= 15:
    for i in range(15, N+1, 15):
        y += 200

print((800 * N) - y)
