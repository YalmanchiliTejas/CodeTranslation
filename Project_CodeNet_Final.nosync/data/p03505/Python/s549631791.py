K, A, B = map(int, input().split())

if A >= K:
    print(1)
    exit()

if A - B <= 0:
    print(-1)
    exit()

up = A - B
cnt = (K - A + up - 1) // up
print(1 + 2 * cnt)