N = int(input())
H = list(map(int, input().split()))
count = 0
m = H[0]
for n in range(N-1):
    if H[n+1] - H[n] >= 0:
        if H[n+1] > m:
            count += 1
            m = H[n+1]
        elif H[n+1] == m:
            count += 1
print(count+1)