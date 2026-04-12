from collections import Counter


if __name__ == "__main__":
    C = Counter()
    N = int(input())
    for c in [chr(n) for n in range(ord("a"), ord("z")+1)]:
        C[c] = 10**8
    for _ in range(N):
        cs = Counter(input())
        C &= cs
    for k, v in C.items():
        print(k*v, end="")
    print()
