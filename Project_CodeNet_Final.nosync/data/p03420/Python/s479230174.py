
def Z(): return int(input())
def ZZ(): return [int(_) for _ in input().split()]

def main():
    N, K = ZZ()
    output = 0
    for b in range(1, N+1):
        output += N//b * max(0, b-K)
        output += max(0, N%b-K+1)
        if K == 0: output -= 1
    print(output)

    return

if __name__ == '__main__':
    main()
