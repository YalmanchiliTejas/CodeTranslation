n = list(map(int, list(input())))
k = int(input())

N = len(n)

a = [[0 for _ in range(k+1)] for _ in range(len(n)+1)]
b = [[0 for _ in range(k+1)] for _ in range(len(n)+1)]
b[0][0] = 1

for i, x in enumerate(n):
    a[i+1][0] = a[i][0] + b[i][0]
    for j in range(1, k+1):
        temp = a[i][j-1] * 9 + a[i][j]
        if x > 0:
            temp += b[i][j] + b[i][j-1] * (x-1)
        a[i+1][j] = temp
        if x == 0:
            b[i+1][j] = b[i][j]
        else:
            b[i+1][j] = b[i][j-1]

#print(a)
#print(b)

print(a[N][k] + b[N][k])