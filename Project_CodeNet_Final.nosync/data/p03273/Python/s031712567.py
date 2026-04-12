H, W = map(int, input().split())
print(*map(lambda l: "".join(l), zip(*[column for column in zip(*[row for row in [input() for _ in range(H)] if "#" in row]) if "#" in column])), sep="\n")