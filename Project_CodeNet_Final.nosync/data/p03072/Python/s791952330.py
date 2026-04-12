N = int(input())
H = list(map(int, input().split()))

result = 1

for i in range(1, N):

    bigger = 0

    for j in range(0, i):
        if H[j] > H[i]:
            bigger += 1

    if bigger == 0:
        result += 1

print(result)
