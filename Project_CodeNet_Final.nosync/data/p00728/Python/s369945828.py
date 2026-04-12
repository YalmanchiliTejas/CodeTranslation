while True:
    n = int(input())
    if n == 0:
        break
    x = []
    for i in range(n):
        x.append(int(input()))
    x = sorted(x)
    x.pop(0)
    x.pop(-1)
    print(sum(x) // len(x))

