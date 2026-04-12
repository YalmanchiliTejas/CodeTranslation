N = int(input())
H = input().split()
H = [int(h) for h in H]
ct = 1
for i in range(N-1):
    maxim = max(H[:i+1])
    if H[i+1] >= maxim:
        ct += 1
print(ct)