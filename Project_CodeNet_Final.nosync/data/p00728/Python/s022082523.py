import sys

while True:
    n = int(sys.stdin.readline().rstrip())

    if n == 0:
        break

    scores = [int(sys.stdin.readline().rstrip()) for i in range(n)]
    result = (sum(scores) - (max(scores) + min(scores))) // (n - 2)

    print(result)