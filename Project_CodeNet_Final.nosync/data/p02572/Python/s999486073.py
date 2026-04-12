MOD = int(1e9+7)

if __name__ == "__main__":
    n = int(input())
    a = [int(i) for i in input().split()]

    sum_a = sum(a) % MOD

    result = 0 

    for value in a:
        sum_a -= value
        result = int(result + value * sum_a) % MOD
    
    print(result)