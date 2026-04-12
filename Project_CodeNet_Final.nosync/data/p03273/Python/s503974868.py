[H, W] = [int(i) for i in input().split()]
l = [input() for i in range(H)]

l1 = [x for x in l if x != '.'*W]

l2 = [''.join(x) for x in zip(*l1)]

l3 = [x for x in l2 if any([y if y != '.' else False for y in x])]

print("\n".join([''.join(x) for x in zip(*l3)]))
