H, W = map(int, input().split())
A = []
for _ in range(H):
    a = list(map(int, input().replace('.', '0').replace('#', '1')))
    A.append(a)

ans1 = []
for a in A:
    if sum(a) != 0:
        ans1.append(a)

ans2 = []
for a in zip(*ans1):
    if sum(a) != 0:
        ans2.append(a)

ans2 = [list(map(str, i)) for i in zip(*ans2)]
for a in ans2:
    print(''.join(a).replace('0', '.').replace('1', '#'))
