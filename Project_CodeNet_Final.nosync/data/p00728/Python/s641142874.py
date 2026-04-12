while True:
    n = int(input())
    if n == 0:
        break
    judges = []

    for i in range(n):
        judges.append(int(input()))

    print((sum(judges) - max(judges) - min(judges)) // (len(judges) - 2))

