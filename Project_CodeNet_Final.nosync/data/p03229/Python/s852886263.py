N = int(input())
L = [int(input()) for _ in range(N)]


if N % 2 == 1:
    L = sorted(L, reverse=True)
    minority = N//2
    majority = N - minority
    A = sum(L[:minority])*2 - sum(L[minority:])*2+sum(L[minority:minority+2])
    B = sum(L[:majority])*2 - sum(L[majority:])*2 - sum(L[majority-2:majority])
    ans = max(A, B)
else:
    L = sorted(L)
    C = sum(L[:N//2])*2 - sum(L[N//2:])*2 + L[N//2]-L[N//2-1]
    D = -C
    ans = max(C, D)
    pass
print(ans)
