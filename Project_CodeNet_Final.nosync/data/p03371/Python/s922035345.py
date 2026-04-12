A, B, AB, A_NUM, B_NUM = map(int, input().split())


if AB * 2 > A + B:
    print(A * A_NUM + B * B_NUM)
    exit()

ans = 0
nikoichi = min([A_NUM, B_NUM])
ans += AB * nikoichi * 2

if A_NUM > B_NUM:
    if A > AB * 2:
        ans += (A_NUM-B_NUM) * AB * 2
    else:
        ans += (A_NUM-B_NUM) * A
elif A_NUM < B_NUM:
    if B > AB * 2:
        ans += (B_NUM-A_NUM) * AB * 2
    else:
        ans += (B_NUM-A_NUM) * B

print(ans)
