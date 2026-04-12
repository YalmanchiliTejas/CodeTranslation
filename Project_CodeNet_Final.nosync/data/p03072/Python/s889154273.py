N = int(input())
H = [int(i) for i in input().split()]
x = 1
for i in range(N-1):
    if H[i+1] >= max(H[:i+1]):
        x += 1
print(x)