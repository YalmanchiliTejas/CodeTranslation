H, W = map(int, input().split())
a = [input() for _ in range(H)]

a = [row for row in a if not all(map(lambda i: i == ".", row))]
a_T = [col for col in zip(*a) if not all(map(lambda i: i == ".", col))]
for row in zip(*a_T):
    print("".join(row))