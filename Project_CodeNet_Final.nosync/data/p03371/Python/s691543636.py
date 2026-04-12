#!/usr/bin/env python3

a, b, c, x, y = list(map(int, input().split()))

numa = 0
numb = 0
numc = max(x, y)*2
value = c*numc

# print(numa, numb, numc, value)

while numc:
    numc_tmp = numc-2
    numa_tmp = max(x-numc_tmp//2, 0)
    numb_tmp = max(y-numc_tmp//2, 0)

    value_tmp = a*numa_tmp+b*numb_tmp+c*numc_tmp
    # print(numa_tmp, numb_tmp, numc_tmp, value_tmp)

    if value_tmp >= value:
        print(value)
        exit()
    numc = numc_tmp
    numa = numa_tmp
    numb = numb_tmp
    value = value_tmp

print(value)
