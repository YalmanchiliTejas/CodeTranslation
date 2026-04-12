def main():
    n = int(input())
    a = list(map(int, input().split()))

    mod = 10**9 + 7
    answer = 0
    sum_a = sum(a) % mod

    for i in range(n):
        sum_a = sum_a - a[i]
        answer += a[i] * sum_a
        answer %= mod

    print(answer)


'''
    for i in range(n):
        sum_sub = 0
        for j in range(i+1, n):
            sum_sub += a[j]
            if sum_sub >= mod:
                sum_sub %= mod
        answer += a[i] * sum_sub
        if answer >= mod:
            answer %= mod
    print(answer)
'''

'''
    for i in range(n):
        for j in range(i+1, n):
            answer += a[i] * a[j]
            if answer >= mod:
                answer %= mod
    print(answer)
'''

if __name__ == "__main__":
    main()
