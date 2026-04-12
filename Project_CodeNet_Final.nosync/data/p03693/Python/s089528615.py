A, B, C = map(int, input().split())
# print("Yes" if C in range(A, B+1) else "No")
# x, y = map(int, input().split())
print("YES" if int("{}{}{}".format(A, B, C)) % 4 == 0 else "NO")