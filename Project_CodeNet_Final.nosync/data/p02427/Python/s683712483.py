n = int(input())
masks = [1 << x for x in range(n)]

for i in range(1 << n):
    sub = [idx for idx, mask in enumerate(masks) if i & mask != 0b00]
    print('{}: {}'.format(i, ' '.join(map(str, sub)))) if len(sub) != 0 else print(f'{i}:')
