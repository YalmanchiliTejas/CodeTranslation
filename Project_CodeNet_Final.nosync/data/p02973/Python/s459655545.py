from bisect import bisect_right
def main():
    N = int(input())
    min_a = 10**9 + 1
    values = []
    ans = 0
    for i in range(N):
        tmp = -int(input())
        idx = bisect_right(values, tmp)
        if idx != len(values):
            values[idx] = tmp
        else:
            values.append(tmp)
            ans += 1

    print(ans)








main()