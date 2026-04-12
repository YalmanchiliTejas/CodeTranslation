X, Y, Z = map(int, input().split())
ans = X // (Y+Z)
if X-(Y+Z)*ans >= Z:
    print(ans)
else:
    print(ans-1)