N,S,K = [input() for i in range(3)]
a = list(S)
b = a[int(K) - 1]
for i in range(int(N)):
    if a[i] != b:
        a[i] = "*"
for i in range(int(N)):
    print(a[i],end="")