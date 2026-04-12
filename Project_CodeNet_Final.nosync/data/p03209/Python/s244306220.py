
N,X = map(int,input().split())

nlen = [0] * (N+1)
nlen[0] = 1

for i in range(N):
    i += 1

    nlen[i] = 3 + nlen[i-1] * 2

    
    
num = [0] * (N+1)

p = 0
b = 0

amari = X


for i in range(N):

    i = N-i

    num[i-1] += 2 * num[i]
    p += num[i]
    b += num[i] * 2

    if 3 + 2 * nlen[i-1]  == amari :

        num[i-1] += 2

        p += 1
        b += 2

        amari = 0

    elif 2 + 2 * nlen[i-1] == amari:

        num[i-1] += 2

        p += 1
        b += 1

        amari = 0

    elif 2 + nlen[i-1] <= amari:

        num[i-1] += 1

        p += 1
        b += 1

        amari -= 2 + nlen[i-1]

    elif 1 + nlen[i-1] == amari:

        num[i-1] += 1

        b += 1

        amari = 0

    elif 1 <= amari:

        b += 1
        amari -= 1

print (p + num[0])