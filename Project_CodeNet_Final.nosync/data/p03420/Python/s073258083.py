#!/usr/bin/env python3

def main():
    n, k = map(int, input().split())
    cnt = 0
    for b in range(k + 1, n + 1):
        cnt += count_a(n, k, b)
    print(cnt)

def count_a(n, k, b):
    assert b > k
    fulls = (n + 1) // b
    rest = (n + 1) % b
    cnt = fulls * (b - k)
    cnt += max(0, rest - k)
    if k == 0:
        cnt -= 1
    return cnt

main()
