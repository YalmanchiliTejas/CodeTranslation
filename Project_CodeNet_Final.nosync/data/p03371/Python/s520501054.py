S = map(int, raw_input().split())
A = S[0]
B = S[1]
C = S[2]
X = S[3]
Y = S[4]

if X > Y:
    A = S[1]
    B = S[0]
    X = S[4]
    Y = S[3]

totals = []
for i in range(Y + 1):
    total = 0
    total += C * 2 * i
    if i < X:
        total += A * (X - i)
    if i < Y:
        total += B * (Y - i)

    totals.append(total)

print(sorted(totals)[0])
