def main():
        
    import numpy as np

    N = int(input())
    numbers = list(map(int, input().split()))

    np_numbers = np.array(numbers, np.int64)

    module = 10 ** 9 + 7

    cumsum = np.cumsum(np_numbers)
    cumsum.tolist()
    summ = cumsum[-1]
    ans = 0

    for i in range(N):
        tmp = (summ - cumsum[i]) % module
        ans += ((np_numbers[i] % module) * tmp) % module
        
        ans %= module
        
        
        

    ans %= module

    print(ans)

if __name__ == '__main__':
    main()
