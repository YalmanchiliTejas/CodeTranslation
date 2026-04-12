def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.reverse()
    
    temp = 0
    a_sum = []

    for i in range(len(a)):
        temp += a[i]
        a_sum.append(temp)

    total = 0
    a_sum.reverse()
    a.reverse()

    for i in range(1, len(a_sum)):
        total += a[i-1]*a_sum[i]
    
    print(total % (10**9+7))

if __name__ == '__main__':
    main()