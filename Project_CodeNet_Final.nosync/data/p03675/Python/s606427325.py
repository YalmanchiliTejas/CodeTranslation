if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    A = reversed(A)
    left = 0
    right = N - 1
    res = [0] * N
    for i,val in enumerate(A):
        if i % 2 == 0:
            res[left] = val
            left += 1
        else:
            res[right] = val
            right -= 1
    print(" ".join(map(str,res)))