N = int(input())
H = [int(X) for X in input().split()]
MAX = H[0]
Count = 1
for T in range(1,N):
    if MAX<=H[T]:
        MAX = H[T]
        Count += 1
print(Count)