H, W = map(int, input().split())

A = [[a for a in input()] for _ in range(H)]
flag = True
while flag:
    flag = False
    # 行方向
    rm = []
    for i, a in enumerate(A):
        if '#' not in a:
            rm.append(i)
    if len(rm) > 0:
        flag = True
        A = [a for i, a in enumerate(A) if i not in rm]
    # 列方向
    rm = []
    A = list(zip(*A))
    for i, a in enumerate(A):
        if '#' not in a:
            rm.append(i)
    if len(rm) > 0:
        flag = True
        A = [a for i, a in enumerate(A) if i not in rm]
    A = list(zip(*A))

for a in A:
    print(''.join(a))
