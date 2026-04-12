#!/usr/bin/env python
# coding: utf-8

def ri():
    return int(input())

def rl():
    return list(input().split())

def rli():
    return list(map(int, input().split()))

def main():
    n, x, m = rli()
    if x == 0:
        print(0)
        return
    if x == 1:
        print(n)
        return
    l = 0
    memo = {}
    a = x
    nums = []
    while a not in memo:
        # print(l, a)
        nums.append(a)
        memo[a] = l
        l += 1
        a = a*a % m
    st = memo[a]
    k = len(nums)
    if n <= k:
        print(sum(nums[:n]))
        return
    su = sum(nums)
    n -= k
    su2 = sum(nums[st:])
    n2 = n//(k-st)
    ans = su
    ans += n2*su2
    n3 = n%(k-st)
    ans += sum(nums[st:st+n3])
    print(ans)


if __name__ == '__main__':
    main()
