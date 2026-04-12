N = int(input())
S = input()
T = [int(s == "o") for s in S]

def solve():
    for A in [[0, 0], [0, 1], [1, 0], [1, 1]]:
        for i in range(2, N):
            A.append(A[-2] ^ A[-1] ^ T[i - 1])
        if (T[-1] == (A[-2] ^ A[-1] ^ A[0]) and
            T[0] == (A[-1] ^ A[0] ^ A[1])):
            return A
    return []

ans = solve()
if ans:
    print("".join("S" if a else "W" for a in ans))
else:
    print(-1)
