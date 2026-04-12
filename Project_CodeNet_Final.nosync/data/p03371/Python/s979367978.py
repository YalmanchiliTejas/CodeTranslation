A, B, C, X, Y = map(int, input().split())

non_AB = A*X + B*Y
if X>Y:
#BをABから作る
    non_B = C*2*Y + A*(X-Y)
#AをABから作る
    non_A = C*2*X
else:
    non_A = C*2*X + B*(Y-X)
    non_B = C*2*Y


# print(min(non_AB, use_AB))
print(min(non_AB, non_A, non_B))


