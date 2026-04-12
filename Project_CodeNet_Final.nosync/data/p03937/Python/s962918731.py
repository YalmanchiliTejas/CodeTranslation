H, W = map(int, input().split())
A = ""
for i in range(H):
    A += input()
# print(A)
sharp = A.count("#")
if sharp == H + W - 1:
    print("Possible")
else:
    print("Impossible")

