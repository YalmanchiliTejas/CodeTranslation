N, X = map(int, input().split())
count = 0

for i in range(100):
    if N == 0:
        count += 1
        break
    elif X == 1:
        break
    elif X == 2**(N+1) - 1:
        count += 2**N
        break
    elif X == 2**(N+2) - 3:
        count += 2**(N+1) - 1
        break
    elif 1 < X < 2**(N+1) - 1:
        X -= 1
        N -= 1
    elif 2**(N+1) - 1 < X < 2**(N+2) - 3:
        count += 2**N
        X -= 2**(N+1) - 1
        N -= 1

print(count)