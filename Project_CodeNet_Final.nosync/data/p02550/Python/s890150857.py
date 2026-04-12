import sys
def input(): return sys.stdin.readline().strip()

def main():
    n, x, m = map(int, input().split())
    if x == 0:
        print(0)
        return
    if x == 1:
        print(n)
        return

    d = {}
    d_idx = {}
    d_unit = {}
    idx = 0
    pow_x = x
    unit = 0
    while idx < n and pow_x not in d:
        d[pow_x] = idx
        d_idx[idx] = pow_x
        unit += pow_x
        d_unit[idx] = unit

        pow_x *= pow_x
        pow_x %= m
        idx += 1
    # x^{2^idx} = 1

    if idx == n:
        print(unit)
        return
    pre_idx = d[pow_x]
    pre_unit = d_unit[pre_idx] - d_idx[pre_idx]
    iter_unit = unit - pre_unit
    ans = pre_unit + iter_unit * ((n - pre_idx) // (idx - pre_idx))
    for i in range((n - pre_idx) % (idx - pre_idx)):
        ans += d_idx[i + pre_idx]
    print(ans)

if __name__ == "__main__":
    main()
