N = int(input())
H = list(map(int, input().split()))

ct = 1
for i in range(N-1):
    if all(H[i+1] >= j for j in H[:i+1]):
        ct += 1

print(ct)
