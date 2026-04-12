from scipy.misc import comb

N = input()
K = int(input())

L = len(N)

if N.count("0") > L - K:
    integer = int(N)
    N = str(integer - integer % 10 - 1)

L = len(N)

if L < K or N[0] == "-":
    print(0)
    quit()

M = ["0"] * L
count = 0
for i in range(L):
    count += bool(int(N[i]))
    M[i] = N[i]
    if count == K:
        M = "".join(M)
        break

index = 0
ans = 0
count = 0
while index < L:
    if int(M[index]):
        count += 1
        n = L - index - 1
        k = K - count + 1
        digit = int(M[index]) - (count != K)
        ans += comb(n, k, exact=True) * 9 ** k + \
               digit * comb(n, k - 1, exact=True) * 9 ** (k - 1)
    index += 1

print(int(ans))