def main():
    n = int(input())
    ans = 1
    arr = list(map(int, input().split()))
    for i in range(1, n):
        for j in range(i):
            if arr[j] > arr[i]:
                break
            if j == i - 1:
                ans += 1
    print(ans)
    return 0
main()