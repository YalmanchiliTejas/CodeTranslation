A, B, AB, X, Y = map(int, input().split())

smaller = X if X < Y else Y
diff = Y - smaller if X < Y else X - smaller
diff_type = 'b' if X < Y else 'a'
cost = 0

if A+B > 2*AB:
    cost += 2*AB*smaller
    # Bを買い足さないと行けない場合
    if diff_type == 'b':
        if B > 2*AB:
            cost += AB*2*diff
        else:
            cost += B*diff
    else:
        if A > 2*AB:
            cost += AB*2*diff
        else:
            cost += A*diff
else:
    cost = A*X + B*Y

print(cost)
