from functools import lru_cache

@lru_cache()
def p(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    n_ = 2**(n + 1) - 1
    if x == n_:
        return 2**n
    if x > n_:
        return p(n - 1, x - n_) + 2**n
    return p(n - 1, x - 1)

def main():
    print(p(*map(int, input().split())))

if __name__ == '__main__':
    main()