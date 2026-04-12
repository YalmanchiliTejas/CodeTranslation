from math import factorial


def comb(n, r):
    return factorial(n) // factorial(r) // factorial(n - r)


N = input()
K = int(input())
ans = 0
if K == 1:
    for i in range(1, len(N)):
        ans += 9
    ans += int(N[0])
elif K == 2:
    for i in range(K, len(N)):
        ans += 81 * comb(i - 1, 1)
    for i1 in range(1, 10):
        for i2 in range(1, 10):
            for p in range(len(N) - 1):
                if str(i1) + "0" * (len(N) - p - 2) + str(i2) + "0" * p <= N:
                    ans += 1
elif K == 3:
    for i in range(K, len(N)):
        ans += 729 * comb(i - 1, 2)
    for i1 in range(1, 10):
        for i2 in range(1, 10):
            for i3 in range(1, 10):
                for p1 in range(1, len(N) - 1):
                    for p2 in range(p1):
                        st = str(i1) + "0" * (len(N) - p1 - 2) + str(i2) + \
                            "0" * (p1 - p2 - 1) + str(i3) + "0" * p2
                        if st <= N:
                            ans += 1

print(ans)
