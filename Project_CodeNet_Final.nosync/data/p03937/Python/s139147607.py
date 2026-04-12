H, W = map(int, input().split())
s = 0
for _ in range(H):
    S = input().rstrip() + "."
    a0 = "."
    A = []
    for i, a in enumerate(S):
        if a==a0:
            continue
        else:
            A.append(i)
        a0 = a
    if len(A) > 2:
        print("Impossible")
        exit()
    if s != A[0]:
        print("Impossible")
        exit()
    s = A[1]-1
print("Possible")