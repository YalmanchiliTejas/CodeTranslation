def LIS(l):
    from bisect import bisect_right
    dp = [l[0]+1]
    for i in range(len(l)):
        if l[i] >= dp[-1]:
            dp.append(l[i])
        else:
            dp[bisect_right(dp, l[i])] = l[i]
    return len(dp)
def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    print(LIS(a[::-1]))
main()