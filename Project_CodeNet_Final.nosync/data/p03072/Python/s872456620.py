N = [int(s) for s in input().split(" ")][0]
Hs = [int(s) for s in input().split(" ")]
print(len([0 for i in range(1, N) if all([Hs[i] >= Hs[j] for j in range(i)])]) + 1)