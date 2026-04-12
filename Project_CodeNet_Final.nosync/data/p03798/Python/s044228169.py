N = int(input())
S = input()
if N == 3:
    if S == "ooo":
        print("SSS")
    elif S == "xxx":
        print("SSW")
    else:
        print(-1)
    exit()
def solve(first, second):
    R = [None] * N
    R[0] = first
    if (S[0] == "o" and R[0] == "S") or (S[0] == "x" and R[0] == "W"):
        R[1] = R[-1] = second
    else:
        R[1] = second
        R[-1] = "S" if second != "S" else "W"
    for i, s in enumerate(S):
        if i == 0:
            continue
        if (s == "o" and R[i] == "S") or (s == "x" and R[i] == "W"):
            new = R[i - 1]
        else:
            new = "W" if R[i - 1] != "W" else "S"
        if i == N - 2:
            if new != R[i + 1]:
                return False, None
        if i == N - 1:
            if new != R[0]:
                return False, None
            else:
                return True, R
        R[i + 1] = new
for f, s in [("S", "S"), ("S", "W"), ("W", "S"), ("W", "W")]:
    ok, result = solve(f, s)
    if ok:
        print("".join(result))
        break
else:
    print(-1)
