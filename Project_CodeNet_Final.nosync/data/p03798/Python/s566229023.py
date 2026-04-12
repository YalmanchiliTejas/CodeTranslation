N = int(input())
S = [1 if a == "x" else 0 for a in input()]
for a, b in ((0, 0), (0, 1), (1, 0), (1, 1)):
    X = [a, b]
    for i in range(N):
        X.append(X[-1]^X[-2]^S[i])
    if X[-2:] == X[:2]:
        print("".join(["W" if x else "S" for x in X[1:-1]]))
        break
else:
    print(-1)