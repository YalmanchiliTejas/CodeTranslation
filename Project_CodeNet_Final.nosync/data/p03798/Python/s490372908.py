import sys
input = sys.stdin.readline

N = int(input())
s = input().rstrip()

start = ["WS", "WW", "SS", "SW"]

for A in start:
    A = list(A)
    for i in range(1, N):
        if (A[i] == "W" and s[i] == "o") or (A[i] == "S" and s[i] == "x"):
            if A[i - 1] == "S":
                A.append("W")
            else:
                A.append("S")
        else:
            A.append(A[i - 1])
    if len(A) == N + 1 and A[0] == A[-1]:
        A = A[:N]
        if (A[0] == "W" and s[0] == "o") or (A[0] == "S" and s[0] == "x"):
            if A[1] != A[-1]:
                print("".join(A))
                sys.exit()
        else:
            if A[-1] == A[1]:
                print("".join(A))
                sys.exit()
print(-1)

