N = int(input())
H = list(map(int, input().split()))
n = 1

for i in range(1,N):
    if max(H[:i]) <= H[i]:
        n += 1
print(n)