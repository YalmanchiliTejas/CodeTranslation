n, x, m = map(int, input().split())

def solve(n, x, m):
    if n == 1:
        return x
    arr = [x]
    for i in range(1, n):
        x = x*x % m
        if x in arr:
            rem = n-i
            break
        else:
            arr.append(x)
    else:
        rem = 0
    sa = sum(arr)
    argi = arr.index(x)
    roop = arr[argi:]
    nn, r = divmod(rem, len(roop))
    return sa + nn*sum(roop) + sum(roop[:r])

print(solve(n, x, m))