N = int(input())
H = [int(i) for i in input().split()]
count = 0
for i in range(1, N+1):
    if H[i-1] == max(H[:i]):
        count += 1

print(count)
