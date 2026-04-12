def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    MOD = 10 ** 9 + 7
    
    sum_a = sum(A)
    sum_squares = sum([a * a for a in A])
    
    ans = (sum_a ** 2 - sum_squares) // 2
    ans %= MOD

    print(ans)
    
    
if __name__ == '__main__':
    main()  