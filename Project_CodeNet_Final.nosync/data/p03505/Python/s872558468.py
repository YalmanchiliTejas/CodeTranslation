K, A, B = map(int, input().split())
if K <= A:
    print(1)
else:
    if A <= B:
        print(-1)
    else:
        K -= A
        print(1 + 2 * (K // (A - B) + int(K % (A - B) != 0)))