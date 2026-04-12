N = int(input())
H = list(map(int,input().split()))

a = 1
for i in range(1,N):
    if H[i] - max(H[:i]) >= 0:
        a += 1
    else:
        pass
print(a)