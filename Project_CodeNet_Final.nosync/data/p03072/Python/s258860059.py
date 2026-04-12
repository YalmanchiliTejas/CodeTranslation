N = int(input())
H = tuple([int(x) for x in input().split(' ')])

out = 1
for i in range(1, N):
    if H[i] >= max(H[:i]):
        out += 1

print(out)