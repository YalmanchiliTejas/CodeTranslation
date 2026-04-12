N = int(input())
H = list(map(int, input().split()))
max = H[0]
a = 1
for i in range(1,N):
    if max <= H[i]:
        a = a+1
        max = H[i]
print(a)