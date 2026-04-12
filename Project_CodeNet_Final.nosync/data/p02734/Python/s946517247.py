def numba_compile(numba_config):
    import os, sys
    if sys.argv[-1] == "ONLINE_JUDGE":
        from numba import njit
        from numba.pycc import CC
        cc = CC("my_module")
        for func, signature in numba_config:
            globals()[func.__name__] = njit(signature)(func)
            cc.export(func.__name__, signature)(func)
        cc.compile()
        exit()
    elif os.name == "posix":
        exec(f"from my_module import {','.join(func.__name__ for func, _ in numba_config)}")
        for func, _ in numba_config:
            globals()[func.__name__] = vars()[func.__name__]
    else:
        from numba import njit
        for func, signature in numba_config:
            globals()[func.__name__] = njit(signature, cache=True)(func)
        print("compiled!", file=sys.stderr)

import numpy as np

def solve(N, S, A):
    mod = 998244353
    dp = np.zeros((N+1, S+1), dtype=np.int64)
    dp[0, 0] = 1
    ans = 0
    for i, a in enumerate(A, 1):
        for j in range(S+1):
            dp[i, j] += dp[i-1, j]
            if j-a >= 0:
                dp[i, j] += dp[i-1, j-a]
            dp[i, j] %= mod
        dp[i, 0] += 1
        ans += dp[i, S]
    print(ans % mod)

numba_compile([
    [solve, "void(i8,i8,i8[:])"]
])

N, S = map(int, input().split())
A = np.array(input().split(), dtype=np.int64)
solve(N, S, A)
