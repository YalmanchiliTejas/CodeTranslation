import sys

input = sys.stdin.buffer.readline

n, x, mod = map(int, input().split())
ans = 0
temp = x
num = 1
# while temp < mod:
#     temp *= x
#     num += 1


A = [0] * (mod + 1)

kouho = {}
if n < mod:
    A[1] = x % mod
    ans += A[1]
    for i in range(2, n + 1):
        A[i] = A[i - 1] * A[i - 1] % mod
        ans += A[i]
        # print(ans)
else:
    A[1] = x
    ans += A[1]
    kouho[A[1]] = 1
    temp = A[1]
    i = 1
    migi = 1
    for i in range(2, mod + 1):
        A[i] = temp * temp % mod
        if A[i] in kouho:
            migi = i
            break
        kouho[A[i]] = i
        temp = A[i]
    saisho = 0
    hidari = kouho[A[i]]
    saisho = sum(A[1:hidari])
    # for i in range(1, hidari):
    #     saisho += A[i]
    cycle_val = sum(A[hidari:migi])
    # cycle_val = 0
    # for i in range(hidari, migi):
    #     cycle_val += A[i]
    cycle = migi - hidari
    if cycle >= 2:

        kaisu = n // cycle
        amari = n % cycle - (hidari - 1)
        amari %= cycle
        kaisu = (n - (amari + hidari - 1)) // cycle
        amari_val = sum(A[hidari : hidari + amari])
        # amari_val = 0
        # for i in range(hidari, hidari + amari):
        #     amari_val += A[i]
        ans = saisho + cycle_val * kaisu + amari_val
    else:
        ans = 0
        if cycle == 0:
            for j in range(1, i + 1):
                ans += A[j]
        else:
            for j in range(1, i + 1):
                ans += A[j]
            ans += (n - i) * A[j]
print(ans)

