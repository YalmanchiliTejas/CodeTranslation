#!/usr/bin/python3.6
n = int(input())
a = [int(item) for item in input().split()]

itr = 0
max_a = max(a)
while max_a >= n:
    for i in range(n):
        if a[i] >= n:
            num = a[i] // n
            a[i] %= n
            for j in range(n):
                if i == j:
                    continue
                a[j] += num
            itr += num
    max_a = max(a)
print(itr)
