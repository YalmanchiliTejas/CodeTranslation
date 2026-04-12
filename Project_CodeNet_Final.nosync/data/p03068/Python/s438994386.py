N = int(input())
S = input()
K = int(input())
a = list(S)
for i in range(0, N):
    if a[i] != a[K-1]:
        a[i] = "*"
b = "".join(a)
print(b)