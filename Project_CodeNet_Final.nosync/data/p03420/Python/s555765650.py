def num_divisors_cnt(n):
    table = [0] * (n + 1)
    
    for i in range(1, n+1):
        for j in range(i, n + 1, i):
            table[j] += 1
    
    return table

def main():
    N, K = map(int, input().split())
    ans = 0
    
    for i in range(K+1,N+1):
        cnt = i - K
        cnt *= N // i
        cnt += max((N % i) - K + 1,0)
        ans += cnt
    if K == 0:
        ans -= N
    print(ans)


if __name__ == "__main__":
    main()