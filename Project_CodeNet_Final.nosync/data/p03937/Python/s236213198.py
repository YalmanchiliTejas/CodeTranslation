H, W = map(int, input().split())
now = 0
for _ in range(H):
    A = input()
    for i in range(W):
        a = A[i]
        if a == "#":
            if i < now:
                print("Impossible")
                exit()
            now = i
        else:
            if i == now:
                print("Impossible")
                exit()
print("Possible")