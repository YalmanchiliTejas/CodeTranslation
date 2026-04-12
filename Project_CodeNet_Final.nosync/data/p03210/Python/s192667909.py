def is_753(X):
    if X == 7 or X == 5 or X == 3:
        return True
    else:
        return False

X = int(input())
if is_753(X):
    print("YES")
else:
    print("NO")
