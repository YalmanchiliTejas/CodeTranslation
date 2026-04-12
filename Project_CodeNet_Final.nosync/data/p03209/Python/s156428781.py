N, X = map(int, input().split())
count = 0
 
def count_patty(N, X, count):
    if N == 0:
        return 1 + count
    elif X == 1:
        return 0 + count
    elif X == 2**(N+1) - 1:
        return 2**N + count
    elif X == 2**(N+2) - 3:
        return 2**(N+1) - 1 + count
    elif 1 < X < 2**(N+1) - 1:
        X -= 1
        N -= 1
        return count_patty(N, X, count)
    elif 2**(N+1) - 1 < X < 2**(N+2) - 3:
        count += 2**N
        X -= 2**(N+1) - 1
        N -= 1
        return count_patty(N, X, count)
 
print(count_patty(N, X, count))