N = int(input())
H = list(map(int, input().split()))
ret = 0
for i in range(N):
    if H[i] == max(H[:i+1]):
        ret += 1
print(ret)