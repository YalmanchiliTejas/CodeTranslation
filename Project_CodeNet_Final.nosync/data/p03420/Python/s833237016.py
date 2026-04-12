def main():
    n, k = map(int, input().split(' '))
    result = 0
    for i in range(1, n+1):
        p = n//i
        result += p*max(0,i-k)
        result += max(0, n%i-k+1)
    if k == 0:
        result -= n
    print(result)
main()