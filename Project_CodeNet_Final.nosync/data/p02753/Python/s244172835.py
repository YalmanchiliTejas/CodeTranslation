N = list(input())
F = True
for i in range(2):
    if N[i] != N[i+1]:
        F = False
if F:
    print("No")
else:
    print("Yes")