N = int(input())
H = []*100
H[:] = map(int, input().split())
ct = 1
for i in range(N-1):
    maxim = max(H[:i+1])
    if H[i+1] >= maxim:
        ct += 1
print(ct)