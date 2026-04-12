H, W = map(int, input().split())
a = [input() for _ in range(H)]
a = [i for i in zip(*a) if i.count('#')]
a = ["".join(i) for i in zip(*a) if i.count('#')]
print("\n".join(a))
