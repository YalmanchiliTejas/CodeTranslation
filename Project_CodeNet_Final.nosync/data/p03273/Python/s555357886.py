h,w = map(int, input().split())
p = [input() for _ in range(h)]
p = [row for row in p if not all(map(lambda i: i == ".", row))]
p = [col for col in zip(*p) if not all(map(lambda i: i == ".", col))]
for row in zip(*p):
    print("".join(row))