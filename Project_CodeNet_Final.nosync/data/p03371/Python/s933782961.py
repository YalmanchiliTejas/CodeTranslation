A, B, C, X, Y = map(int, input().split())

ans = []

ans.append(A*X + B*Y)  # Aピザ、Bピザだけを使って買う

ans.append(2 * C*max(X, Y))  # ABピザだけを使って買う

if X > Y:
    ans.append(C*2*Y + A*(X-Y))

else:
    ans.append(C*2*X + B*(Y-X))

print(min(ans))
