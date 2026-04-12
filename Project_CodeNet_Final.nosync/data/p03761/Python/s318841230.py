n = int(input())
S = [''.join(sorted(input())) for _ in range(n)]
x = S[0]
for i in range(1, n):
    j, k = 0, 0
    tmp = ''
    while j < len(x) and k < len(S[i]):
        if x[j] == S[i][k]:
            tmp += x[j]
            j += 1
            k += 1
        else:
            if x[j] < S[i][k]:
                j += 1
            else:
                k += 1
    x = tmp
print(x)
