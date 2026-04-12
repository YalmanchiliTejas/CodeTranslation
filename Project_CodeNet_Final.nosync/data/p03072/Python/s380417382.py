import numpy as np

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    maxi = 0
    for i in range(N):
        if(A[i] >= maxi):
            ans += 1
        maxi = max(maxi, A[i])
    print(ans)