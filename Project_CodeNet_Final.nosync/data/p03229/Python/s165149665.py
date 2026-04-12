N = int(input())
A = []
for i in range(N):
    a = int(input())
    A.append(a)

A = sorted(A)

P1 = [0 for _ in range(N)]
for i in range(N):
    if i == 0:
        P1[0] = 1
    elif i%2 == 1:
        if i == N-1:
            P1[i] = -1
        else:
            P1[i] = -2
    else:
        if i == N - 1:
            P1[i] = 1
        else:
            P1[i] = 2

P1 = sorted(P1)

P2 = [0 for _ in range(N)]
for i in range(N):
    if i == 0:
        P2[0] = -1
    elif i%2 == 1:
        if i == N-1:
            P2[i] = 1
        else:
            P2[i] = 2
    else:
        if i == N - 1:
            P2[i] = -1
        else:
            P2[i] = -2

P2 = sorted(P2)

ans1 = 0
ans2 = 0
for i in range(N):
    ans1 += P1[i]*A[i]
    ans2 += P2[i]*A[i]

ans = max(ans1,ans2)

print(ans)
